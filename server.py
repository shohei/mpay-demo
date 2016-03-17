#!/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
import os
import tornado.ioloop
import tornado.web
import tornado.autoreload
import serial

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.render("index.html")
    def post(self):
        doSendMoney()

def doSendMoney():
    print("send money start")
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

application = tornado.web.Application([
    (r"/", MainHandler),
    ],
    debug=True,
    template_path=os.path.join(os.getcwd(),  "templates"),
    static_path=os.path.join(os.getcwd(),  "static"),
    )


if __name__ == "__main__":
    ser = initSerialPort()
    application.listen(8888)
    print("Server is up ...")
    tornado.ioloop.IOLoop.instance().start()


