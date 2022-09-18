# StandLight
라즈베리파이를 이용한 탁상용 스탠드 개발 코드


![image](https://user-images.githubusercontent.com/113006264/190899056-b2f1fdb5-275a-430a-9aa5-523a203451e5.png)


# 스탠드 #7
1. 버튼1 : LED 밝기 조절
2. 버튼2 : LCD(시계) back light ON/OFF
3. LCD 0 : LED 모드 상태 표시 (off,1,2,3,4,5)
    LCD 1: 시계 (hh:mm:ss)
4. 온습도 센서
   LCD 0/1: 온도, 습도
   온도가 높으면 warning message LCD 출력 + LCD LIGHT OFF MODE
   온도가 높으면 선풍기 동작
   정상온도 선풍기 꺼짐
5. 초음파센서 : 사용자 부재시 LIGHT OFF, 사용자 접근시LIGHT ON
6. 버튼3 : DC MOTER와 PWM를 이용한 선풍기 ON/OFF
7. 버튼4 : 1.시계 카운트 업 , 1 -> 2.시계 정지 , 2 -> 3 현재시간
