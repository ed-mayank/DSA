import socket
import sys

try:
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('127.0.0.1', 1244))
    print("Client connected with server")
except socket.error as err:
    print(err)

payload="Hey Server!!"

try:
    while True:
        client_socket.send(payload.encode('utf-8'))
        data = client_socket.recv(1024)
        print(str(data))
        more = input("Do you want to talk to server: ")
        if more.lower() == 'y':
            payload=input("Enter your query: ")
        else:
            break
except KeyboardInterrupt:
    print("Exited by user")