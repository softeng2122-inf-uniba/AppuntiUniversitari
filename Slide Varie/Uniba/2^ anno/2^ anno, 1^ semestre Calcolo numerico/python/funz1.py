# -*- coding: utf-8 -*-
"""
Created on Sun Oct 16 21:58:56 2016

@author: felix
"""

def funz1(x,ord=0):
    if ord==0:
        y=x-cos(x)
    elif ord==1:
        y=1+sin(x)
    else:
        print("secondo argomento non definito")
        y=NaN
    return y