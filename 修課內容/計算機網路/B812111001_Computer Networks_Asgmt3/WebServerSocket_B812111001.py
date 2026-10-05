#import socket module
from socket import *
import sys # In order to terminate the program

import os
print(f"當前工作目錄: {os.getcwd()}") # 顯示工作位置

#Prepare a sever socket
serverSocket = socket(AF_INET, SOCK_STREAM) # 創建 TCP socket
serverPort = 6789 # Port number // 選擇使用的port
serverSocket.bind(("192.168.26.158", serverPort)) # associate the server port number with this socket // 連接伺服器IP與Socket port
# 打開 cmd 輸入 ipconfig/all 也可得到 本機IP:192.168.26.158
serverSocket.listen(1) # wait and listen for some client to knock on the door // 等待 client 連接
while True:
    #Establish the connection
    print('Ready to serve...')
    connectionSocket, addr = serverSocket.accept() # 伺服器等待accept function 接收 request，並創建另一個與client傳輸的個別socket

    try:
        message = connectionSocket.recv(1024).decode() # receives message from client // 接收到的 message 內容 // 緩衝區大小1024byte
        # 接收到的訊息是以2進制 return，加上.decode改為 return string
        filename = message.split()[1] # 將 message以空格進行切割，並提取第一個字元
        print(f"Request File: {filename[1:]}")
        f = open(filename[1:]) # 除去檔案名稱的第一個字元，通常是 /，獲取真實檔案名
        outputdata = f.read() # 讀取 file 內容並作為輸出資料存取

        #Send one HTTP header line into socket
        connectionSocket.send("HTTP/1.1 200 OK\r\n\r\n".encode()) # sends a 200 OK header line //此情況為有這個檔案，因此 header line 應為 200 OK

        #Send the content of the requested file to the client
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())
        connectionSocket.send("\r\n".encode())

        print("File sent successfully !")
        connectionSocket.close()
    
    except IOError:
        #Send response message for file not found
        connectionSocket.send("HTTP/1.1 404 Not Found\r\n\r\n".encode()) # 此情況為沒有此要求的檔案，因此 header line 應為 404 Not Found
        # 一對 \r\n\r\n 表示 HTTP 標頭的結束，後面接 HTTP 主體 (body) 內容
        connectionSocket.send("<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n".encode())
        # <html> HTML 文件的根標籤
        #    <head></head> <!-- 空的 <head> 區域 --> 頁面的頭部，這裡沒有包含任何資訊
        #    <body>
        #        <h1>404 Not Found</h1> <!-- 顯示錯誤訊息 --> 內容
        #    </body>
        # </html>

        #Close client socket
        print("File does not exist !")
        connectionSocket.close() 

    serverSocket.close() # close server socket
    sys.exit() #Terminate the program after sending the corresponding data // 結束程式執行