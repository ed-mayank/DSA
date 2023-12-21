import socket
import sys

try:
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
except socket.error as err:
    print("Socket creation failed!!")
    print(err)
    sys.exit()
    
HOST="127.0.0.1"
PORT=34623

try:
    server_socket.bind((HOST, PORT))
    server_socket.listen(5)
    
    while(True):
        print("Server is waiting for connection!!")
        client_socket, addr = server_socket.accept()
        print("Client connected ", addr)
        while True:
            data = client_socket.recv(1024)
            if not data or data.decode('utf-8')=='END':
                break
            print("Data received from client: ", data.decode('utf-8'))
            try:
                client_socket.send(bytes('Hey Client', 'utf-8'))
            except:
                print("Exited by user!!")
        client_socket.close()
        break
    server_socket.close()
except socket.error as err:
    print("Failed to bind!!")
    print(err)
    sys.exit()