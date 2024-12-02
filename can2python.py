import can
import socket

# CAN 설정
channel = "COM5"  # Windows에서 COM 포트 이름
bitrate = 500000  # Bitrate 설정

# TCP 설정
TCP_IP = "127.0.0.1"  # 서버 주소 (로컬)
TCP_PORT = 65432       # 서버 포트
BUFFER_SIZE = 1024

# CAN 인터페이스 초기화
bus = can.interface.Bus(bustype='slcan', channel=channel, bitrate=bitrate)

print("수신 대기 중... (Ctrl+C로 종료)")

# TCP 클라이언트 초기화
tcp_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_client.connect((TCP_IP, TCP_PORT))

try:
    while True:
        # CAN 메시지 수신
        received_msg = bus.recv(timeout=None)  # None이면 무기한 대기
        if received_msg:
            # TCP로 송신할 데이터 생성 (16진수 변환)
            msg_data = f"ID: {received_msg.arbitration_id}, DATA: {[hex(byte) for byte in received_msg.data]}"
            tcp_client.send(msg_data.encode('utf-8'))
            
            # 송신 데이터 출력
            print("송신한 데이터:", msg_data)
except KeyboardInterrupt:
    print("\n수신 종료")
finally:
    # 종료 처리
    bus.shutdown()
    tcp_client.close()
