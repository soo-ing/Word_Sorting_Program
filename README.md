
![1](https://user-images.githubusercontent.com/84956281/121365638-c8aaf080-c973-11eb-94d9-e56e8f5dde94.png)


프로그램 소개
-------------
3가지의 정렬 알고리즘을 사용해 영어 단어를 정렬하는 프로그램을 만들고 파이프로 입력받아 출력하는 프로그램


동작 시나리오
--------------
1. ./word_extract -d sample2.txt 명령을 이용하여 sample2.txt 파일에 있는 영어 문장을 영어 단어 단위로 추출
2. 추출한 영어 단어를 getchar()를 이용하여 입력
3. strtok()을 이용하여 단어를 쪼갠 후 영어 단어 각각의 빈도수를 측정하여 영어 단어는 table.name에, 빈도수는 table.count에 삽입   
4. 이후로 3가지의 정렬 알고리즘을 사용하여 정렬 프로그램을 구현   
***
##### 첫 번째
영어단어의 오름차순으로 영어 단어와 빈도수를 출력하는 것을 삽입정렬을 이용하여 구현   
##### 두 번째
빈도수의 오름차순으로 영어 단어와 빈도수를 출력하는 것을 쉘 정렬로 구현   
##### 세 번째
제시된 영어 단어를 찾아 해당 단어와 빈도수를 함께 출력하는 것을 힙 정렬을 이용하여 구현
***
   
5. getopt()를 이용하여 옵션 값을 받아 옵션마다 출력할 수 있도록 구현
***
##### 첫 번째
./word_extract –d sample2.txt | WordCount -a   
##### 두 번째
./word_extract –d sample2.txt | WordCount -b   
##### 세 번째
./word_extract –d sample2.txt | WordCount -c Beautiful   
***   

프로그램 구현
----------

