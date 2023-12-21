import socket  
# Here, we are creating the Client socket  
if __name__ == '__main__':  
    host = '127.0.0.1'  
    port = 8060  
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
# Here, we are giving the connection with the Server  
    sock.connect((host, port))  
    while True:  
        filename = input('Input the filename you need to send: ')  
        try:  
            # Here, we are reading the file and sending the data to server  
            fi = open(filename, "r")                 # here, we are opening the file in the read mode  
            data = fi.read()  
            if not data:  
                break  
            while data:  
                sock.send(str(data).encode())  
                data = fi.read()  
            # Here, we are closing the file after the data is sent successfully  
            fi.close()  
        except IOError:  
            print('You have entered an invalid filename!\Kindly please enter a valid name')  