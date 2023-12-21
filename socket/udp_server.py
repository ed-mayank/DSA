import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(('127.0.0.1', 12345))

while True:
    data,addr=server_socket.recvfrom(4096)
    print("Message from client: ",str(data))
    msg = bytes("Hello, I am UDP server!!".encode('utf-8'))
    server_socket.sendto(msg, addr)