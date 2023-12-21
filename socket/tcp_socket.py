import socket
import sys

try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
except socket.error as err:
    print("Failed to create socket")
    print(err)
    sys.exit()
    
print("Socket created successfully!!")
target_host = "www.python.org"
target_port = 80

try:
    sock.connect((target_host, target_port))
    print(f"Socket connected to {target_host} on port number {target_port}")
    sock.shutdown(2)

except socket.error as err:
    print("Failed to connect!!")
    print(err)
    sys.exit()