import socket
import os
#client program

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
process_id = str(os.getpid())

count = 0
while True:
       print (os.getpid())
       m = input("Enter data to send : ")
       res = s.sendto(m.encode('utf-8'), ('127.0.0.1',12345))
       data, addr = s.recvfrom(1024)
       if count == 0: 
           print (str(data.decode()))
           count = 1
