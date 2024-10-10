# Game Framework Project 

### 24.10.07
▶ 파일 구조
  - MEGA_Client 
    - Client 영역 (WinAPI Project, MEGA_Lib 참조)
  - MEGA_Lib 
    - 공유 프로젝트 빌 목적 (정적 Library, MEGA_Source 참조)
  - MEGA_Source 
    - Clinet에서 사용할 기능들의 모음 (공유 프로젝트)

▶ WinAPI Message 처리
  - PeekMessage 함수 사용 : 게임은 사용자의 입력이 없어도 진행되어야 한다.   

▶ Application Class
  - Clinet 영역으로 프로그램 초기화 및 실행
  - 단 하나만 존재해야 하기 때문에, Singleton 패턴 이용   

***

### 24.10.10
▶ 윈도우 창 크기 설정
  - WinMain에서 hWnd, width, height를 인수로 받아 AdjustWindowRect 함수 이용
    
▶ hdc 설정
  - 화면 깜빡임 증상을 해결하기 위해, HDC backHdc, HBITMAP backBuffer 생성
  - 실제로 그리는 영역은 backHdc, backHdc에 그려진 내용을 hdc에 복사하는 방식으로 구현

▶ Delta Time
  - 구동 환경에 관계없이 동일한 프로그램 실행을 보장하기 위해 DeltaTime 구현
  - QueryPerformanceFrequency & QueryPerformanceCounter 를 이용하여, 고유한 CPU 주파수 및 프로그램 시작 후 경과된 카운트를 저장
  - 동작에 소요된 시간을 계산, 소요된 시간을 고유의 주파수로 나누어 deltaTime을 계산
  - 동작간의 정확히 소요된 시간을 계산하기 위해 매번 초기화한다.

▶ Input
  - ASCII 코드를 이용, 사용하고자 하는 키를 미리 생성
  - Key 구조체 { 키, 상태, 눌림 }
  - Key 구조체를 자료형으로 한 벡터에 저장 (모든 키는 항상 검사되어야 하며, 키는 정해져 있다.)
  - 키의 입력 상태에 따른 키 상태 업데이트 -> None, Down, Press, Up
  -  HWND GetFocus 함수 이용, 활성화된 Wnd가 없을 경우 KeyClear 진행
