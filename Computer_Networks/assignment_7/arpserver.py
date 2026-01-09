import socket
table={
    '192.168.1.1':'1E.4A.4A.11',
    '192.168.2.1':'5E.51.4B.01',
    '192.168.1.3':'4B.35.CD.32',
    '198.51.100.1':'00.51.4B.bf',
    '192.168.100.3':'00.35.CD.32',
    '198.51.100.1':'00.51.4B.bf',
    '192.168.100.3':'00.35.CD.32'
} #translate IP address to physical addresses. 
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('',1234))
s.listen()
#communication happens over the physical address (MAC address) 
clientsocket,address = s.accept()
print("Connection from", address, "Has Established")
#ARP finds the hardware address of a host from its known IP address
ip = clientsocket.recv(1024)
ip = ip.decode("utf-8")
mac=table.get(ip,'No entry from given address')
clientsocket.send(mac.encode())
