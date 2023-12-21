import socket
from _thread import *

server_socket = socket.socket()

HOST="127.0.0.1"
PORT=1244
threadCount=0

try:
    server_socket.bind((HOST,PORT))
except socket.error as err:
    print(err)
    
print("Waiting for connection")
server_socket.listen(5)

def client_thread(conn):
    conn.send("Welcome to server".encode('utf-8'))
    while True:
        data = conn.recv(1024)
        print(str(data))
        reply = "Hello I am server"+data.decode('utf-8')
        if not data:
            break
        conn.sendall(str.encode(reply))
    conn.close()
    
while True:
    client,addr=server_socket.accept()
    print("Connected to ", addr[0], str(addr[1]))
    start_new_thread(client_thread,(client,))
    threadCount+=1
    print("Thread number: ", threadCount)
    
server_socket.close()