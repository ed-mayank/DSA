import socket                      # here, we are importing the socket library into our program  
if __name__ == '__main__':  
    # Here, we are defining the Socket  
    host = '127.0.0.1'  
    port = 8060  
    tclient = int(input('Enter the total number of clients: '))  
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
    sock.bind((host, port))  
    sock.listen(tclient)  
    # Here, we are establishing the Connections to the server  
    connections = []  
    print('Initiating the clients')  
    for i in range(tclient):  
        conn = sock.accept()  
        connections.append(conn)  
        print('Successfully Connected with the client', i+1)  
    fileno = 0  
    idx = 0  
    for conn in connections:  
        # Here, we are receiving the File Data  
        idx += 1  
        data = conn[0].recv(1024).decode()  
        print(data)
        if not data:  
            continue  
    # Here, we are creating a new file at the server end and writing the data  
        filename = 'output' + str(fileno) +'.txt'  
        fileno = fileno+1  
        f = open(filename, "w")          # here, we are opening a file in the write mode  
        while data:  
            if not data:  
                break  
            else:  
                f.write(data)             # here, we are writing the data to the file  
                data = conn[0].recv(1024).decode()  
        print()  
        print('Receiving the file from client', idx)  
        print()  
        print('Received successfully! The New filename is:', filename)  
        f.close()          # here, we are closing the file  
    # Here, we are closing all the Connections  
    for conn in connections:  
        conn[0].close() 