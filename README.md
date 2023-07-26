# 22_1_OSS_Project

## What is Online Judge

[Youtube](https://www.youtube.com/watch?v=DqtGV0Hh5v0)

문제가 주어지고 유저가 소스코드를 제출하면 정답이나 오답 여부를 판별해주는 시스템을 온라인 저지 라고 부릅니다. 먼저 온라인 저지의 동작 방식에 알아봅시다.

1. 먼저 크게 유저와 서버 두 부분으로 나눌 수가 있습니다. 서버는 문제의 입력 데이터와, 정답 데이터를 들고 있습니다.
2. 유저가 서버로 소스코드를 제출하면, 서버는 소스코드를 실행하여 입력 데이터를 넣습니다.
3. 입력 데이터를 넣어서 나온 출력 데이터를 서버의 정답 데이터와 비교합니다.
4. 유저의 출력 데이터와 서버의 정답 데이터가 모두 일치하면 정답이라고 판정하고, 그렇지 않다면 오답이라고 판정하여 유저에게 결과를 알려줍니다.

---

그래서 우리가 만들어야 할 파일은 크게 data generator, validator, solution, chekcer 파일 이렇게 4개가 있습니다.

- data generator 파일은 말 그대로 입력 데이터를 동적으로 만들어주는 파일입니다. 문제별로 다르지만 대개 한 문제당 데이터 50개 ~ 200개로 채점을 진행합니다. 이 200개의 파일을 사람이 일일이 다 작성하기란 매우 힘듭니다. 그래서 랜덤함수로 작성된 data generator 파일을 실행하여 랜덤시드를 넣기만 하면 여러개의 데이터를 한번에 생성할 수가 있습니다.
- validator 파일은 data generator을 실행하여 나온 data 파일이 문제에 입력조건에 부합하는지 검증하는 파일입니다. data generator는 사람이 작성한 소스코드를 script를 통해 동적으로 생성되기 때문에 의도치 않은 data가 생성될 수도 있습니다. 그래서 validator가 그런 data를 필터해주고 에러를 띄워주는 역할을 하는거죠. 예를 들어 두 int형 양의 정수의 합을 구하는 문제에서, data를 만드는 과정에 데이터 상에 음수가 포함되어 있거나 아니면 int형 범위를 넘어서는 데이터가 생성될 수도 있습니다. 이때 validator를 거치면 잘못된 데이터를 찾아낼 수 있는 것입니다.
- solution 파일은 말 그대로 본인이 만든 문제를 푸는 소스코드입니다. 문제의 정답 소스코드는 반드시 필수로 포함되어야 하는데, 상황에 따라서는 문제의 오답 소스코드를 일부러 넣기도 합니다. 이렇게 정답 소스코드와 오답 소스코드를 동시에 실행해보면 데이터가 제대로 생성되었는지 확인할 수 있기 때문에 유용합니다.
- 마지막으로 checker 파일의 역할은 유저가 제출한 답안으로 실행하여 나온 output파일과 실제 정답 파일을 비교할 때 실행되는 파일입니다. 만약 문제의 정답이 유일한 문제라면, 단순 비교만 하면 되기 때문에 polygon에서 제공해주는 라이브러리를 가져다 쓰면 됩니다. 그런데 어떤 문제는 문제의 정답이 여러 개인 문제가 있습니다. 그럴 경우에는 사용자의 정답을 입력으로 받아서 그 정답이 정해진 조건을 만족하는지 작성하여야 합니다.

위 파일들을 만들때 도움되는 testlib.h라는 polygon에서 제공해주는 라이브러리 헤더파일이 있습니다.

## 기본적인 polygon 사용법

### 각종 파일 생성

validator를 만들어 보겠습니다. 이 문제의 입력 조건은 크게 두가지가 있었는데, 하나는 a와 b가 int형 양의 정수라고 했었고, 두 번째는 b가 a보다 크다고 했습니다. 따라서 이 두 조건을 모두 만족하는 입력 데이터만 통과시키고 둘 중 하나라도 만족하지 못하면 그 데이터를 제외시켜야 합니다. 그래서 readInt함수와 ensuref 함수로 검증을 하면 됩니다.

그 다음은 data generator를 만듭니다. 간단하게 숫자 2개만 랜덤하게 생성하면 되니깐 rnd.next함수를 부르면 됩니다. 그리고 실행하면서 main함수에 인자를 넣어줄 수 있는데, 보통 입력 값의 스케일을 조절할 때 인자를 넣어줍니다. 그래서 저는 RANGE라는 변수를 만들고 얘는 argv[1]의 값을 받도록 하겠습니다. data generator는 tests에서 확인하실 수 있는데, 밑에 있는 script에 data genrator를 실행할 커맨드를 적으면 됩니다.

```
dataGenA 100 > $
```

이렇게 적으면 아까 main함수에 전달할 인자에 숫자 100이 들어간다고 생각하시면 됩니다. 이렇게 해서 data generator를 실행해보면 제가 방금 만들었던 validator를 통한 검증도 자동적으로 거쳐서 나오게 됩니다. 그리고 이 커맨드를 반복문을 돌려서 한꺼번에 여러 개를 만들고 싶으시다면

```
<#list 1..60 as i>
 dataGenA ${i} > $
</#list>
```

이렇게 만들면 됩니다.

마지막으로 checker를 보겠습니다. 이 문제는 정답이 유일하기 때문에 단순 비교만 하면 됩니다. 따라서 polygon에서 제공해주는 checker 중에서 lcmp.cpp를 사용하면 됩니다.

### Stress

이번에는 polygon의 또다른 기능 중 하나인 stress에 대해서 알아보겠습니다. 말 그대로 스트레스 테스트를 시행하는 겁니다. 스트레스 테스트를 시행하기 위해서는 data generator와 solution파일에서 설명했던, 정답 코드와 오답 코드가 최소 하나 이상은 필요합니다.  
script pattern에는 data generator에서 작성했던 스크립트 쓰듯이 넣으면 됩니다. 이렇게 넣고 테스트를 실행하면 얘가 임의의 시드값을 넣으면서 정답 코드와 오답 코드의 결과값이 달라질 때까지 실행합니다. 현재 저의 오답코드의 문제점이 두 수의 합이 int형 범위를 넘어갈 때 생기잖아요. 따라서 스트레스트 테스트의 결과도 그 케이스를 찾아줄거라고 예상할 수 있습니다.  
스트레스 테스트의 의의는 data generator를 통해 랜덤으로 생성되는 데이터가 과연 정답 코드와 오답 코드를 구분할 수 있느냐 입니다. data는 필연적으로 랜덤함수에 의존하여 만들어지기 때문에 오답 코드의 카운터 케이스를 걸러내지 못할 수도 있고,아니면 처음부터 data generator를 잘못 만들었을 수도 있습니다. 따라서 이 스트레스 테스트는 본인이 만든 data 의 유효성을 검증하기 위해서 사용됩니다.

## custom checker

다음으로 두 번째 문제였던 연립방정식 문제를 만들어보겠습니다. 이 문제는 이전 문제랑 checker부분만 다르고 나머지는 다 비슷하니 checker만 살펴보겠습니다.  
먼저 inf.readInt함수를 통해서 문제에서 주어진 a,b,c값을 가져오고 ouf.readInt()함수를 통해서 유저가 제출한 답안인 x,y를 들고오도록 하겠습니다. 그래서 우리가 해야할 일은 a*x + b*y 가 c값이 나오는지만 확인해보면 됩니다. 그래서 c값이 나온다면 quitf함수를 불러서 ok값을 넘겨주면 됩니다. 그런데 만약 유저가 정답 없음에 해당하는 x=-1,y=-1을 제출했다면, 우리는 실제로 문제의 정답이 존재하지 않은지, 아니면 정답이 존재함에도 사용자가 찾지 못한 것인지 판별해야 합니다. 그럴 때는 실제 정답을 불러와야 합니다. 따라서 ans.readInt함수를 호출해서 실제 정답도 -1인지 확인해보면 됩니다. 실제 정답이 -1이면 정말로 답이 없는 입력이었다는 뜻입니다. 만약 -1이 아니었다면 정답이 존재하는데 유저가 답을 못찾았다는 의미이므로 quitf에 wrong answer를 띄워주면 됩니다. 마지막으로 유저가 정답을 찾긴 찾았는데 더한 값이 c값과 같지 않다면 역시 wrong answer를 띄워주면 됩니다.

## 느낀점

요즘 많은 분들이 알고리즘 문제를 푸는 경우가 많은데, 실제로 이 문제들이 어떻게 만들어지는지에 대해서는 모르는 경우가 대부분입니다. 문제를 출제할 기회가 많지는 않겠지만, 온라인 저지의 작동 원리와 그곳에 사용되는 파일들이 어떻게 만들어지는지 한번 쯤 알아보는 것도 흥미로운 주제라고 생각을 했다. 나 역시도 문제 출제를 조금밖에 안 해보았기에, 아직 완전히 익숙하다고 할 수는 없겠지만 이번 프로젝트에서 자료를 만들면서 정리를 하는 계기가 되어 좋은 경험이었던 같다.
