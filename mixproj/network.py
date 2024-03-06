import socket
import time
import io
import os
import sys
import math
import random
import datetime
import re 
import json
import torch
import numpy
import matplotlib.pyplot as plt
import requests
"""
def eat_bandwidth():
    # 设置目标服务器的地址和端口
    target_host = "speedtest.net"
    target_port = 80
    
    # 创建一个TCP套接字
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        # 连接到目标服务器
        client.connect((target_host, target_port))
        
        # 发送一些数据，这里可以根据需要发送更多数据
        client.send(b"GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n")
        
        # 接收响应数据
        response = client.recv(4096)
        
        # 打印响应数据（可选）
        print(response)
        
        # 关闭连接
        client.close()
        
    except Exception as e:
        print("Error:", e)
"""

# 准备数据
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

# 创建图形和子图
fig, ax = plt.subplots()

# 绘制折线图
ax.plot(x, y, marker='o', linestyle='-')

# 设置标题和坐标轴标签
ax.set_title('Prime Numbers')
ax.set_xlabel('Index')
ax.set_ylabel('Value')
# if __name__ == "__main__":
#     while True:
#         eat_bandwidth()
# 显示图形
plt.show()