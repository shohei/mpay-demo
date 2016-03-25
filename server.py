#!/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
import os
import tornado.ioloop
import tornado.web
import tornado.autoreload
import serial
import threading
import sys
import signal

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.render("index.html")
    def post(self):
        doSendMoney()

def doSendMoney():
    print("Tornado server: send money start")
    global ser
    ser.write("t")

def initSerialPort():
    try:
        ser = serial.Serial(
        port='/dev/tty.usbmodem14141',
        baudrate=19200,
    )
        return ser
    except Exception:
        print('no such port exists')
        print('Exising server...')
        exit(-1)

def startReadThread():
    t2 = threading.Thread(target=thread2)
    t2.start()
    return t2

def thread2():
    while True:
        global ser
        data = ser.read()
        sys.stdout.write(data)


def signal_handler(signal, frame):
    print('You pressed Ctrl+C!')
    global t2
    t2._Thread__stop()
    sys.exit(0)


application = tornado.web.Application([
    (r"/", MainHandler),
    ],
    debug=True,
    template_path=os.path.join(os.getcwd(),  "templates"),
    static_path=os.path.join(os.getcwd(),  "static"),
    )


if __name__ == "__main__":
    # ser = initSerialPort()
    # t2 = startReadThread()
    # signal.signal(signal.SIGINT, signal_handler)    
    application.listen(8888)
    print("Server is up ...")
    tornado.ioloop.IOLoop.instance().start()


