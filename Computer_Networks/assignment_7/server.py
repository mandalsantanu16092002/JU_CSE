import socket      
import os 

#AF_INET used for IPv4
#SOCK_DGRAM used for UDP protocol
s = socket.socket(socket.AF_INET , socket.SOCK_DGRAM )
#binding IP and port 

print (os.getpid())

available_ip_queue = []
available_ip_queue.append('0.0.0.0')
available_ip_queue.append('0.0.0.1')
available_ip_queue.append('0.0.0.2')

connected_clients = []
s.bind(('127.0.0.1',12345))

print("........................Server started .........................")
print("<<<<<<<<<<Waiting for Client>>>>>>>") 
#recieving data from client
#dictionary to handle all the clients 
clients = {}
while True:
    data, addr = s.recvfrom(1024)
    dormant_clients = []
    if addr in clients.keys():
        s.sendto('acknowledgement msg'.encode(), addr)
        print (str (data.decode()) + ' Received from client with ip :- ' + str(clients[addr]))
    else:
        msg = '' 
        if len(available_ip_queue) == 0: 
            msg = '......THERE IS NO MORE IP AVAILABLE......'
        else:
            msg = 'hello ,new client your assigned ip is :- ' + available_ip_queue[0]
            clients[addr] = available_ip_queue[0]
            available_ip_queue.pop(0)
        s.sendto(msg.encode ('utf-8'), addr)       
