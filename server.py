#!/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
import os
import tornado.ioloop
import tornado.web
import tornado.autoreload

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.render("index.html")

application = tornado.web.Application([
    (r"/", MainHandler),
    ],
    debug=True,
    template_path=os.path.join(os.getcwd(),  "templates"),
    static_path=os.path.join(os.getcwd(),  "static"),
    )

if __name__ == "__main__":
    application.listen(8888)
    print("Server is up ...")
    tornado.ioloop.IOLoop.instance().start()


