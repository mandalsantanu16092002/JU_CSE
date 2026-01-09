import socket

Host = '127.0.0.2'  # The server's hostname or IP address
FTPport = 65300        # The port used by the server

name = input("Enter name of the client: ")
#moves files between local and remote file systems

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    choice = int(input("Press 1 to retrieve file.\nPress 2 to quit.\n"))
    if choice == 1:
        s.connect((Host, FTPport))
        s.send(bytes(name, "utf-8"))
        filename = input("Enter filename to be searched: ")
        s.send(bytes(filename, "utf-8"))
        data = s.recv(1024).decode()
        print("The contents of the file: \n" + data + "\n\n")
        s.close()
    elif choice == 2:
        break
    else:   
        print("Invalid Choice. Try Again.")