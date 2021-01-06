#!/usr/bin/env python

# Author: O.R.Senthil Kumaran <senthil@uthcode.com>
# Credits: Example Python Snipppet from the Phidget Library.
# Adapted from TextLCD-simple.py by 'Adam Stelmack'.


from ctypes import *
import sys
from time import sleep

#Phidget specific imports
from Phidgets.Phidget import PhidgetID
from Phidgets.PhidgetException import PhidgetErrorCodes, PhidgetException
from Phidgets.Events.Events import AttachEventArgs, DetachEventArgs, ErrorEventArgs
from Phidgets.Devices.TextLCD import TextLCD, TextLCD_ScreenSize

# for twitter

import tweetstream
import json
import urllib.request, urllib.error, urllib.parse
import re

USER= "username"
PASSWORD = "yourpassword"
SEARCHTERM = "royalwedding"

stream = tweetstream.TweetStream(USER, PASSWORD)

#Create an TextLCD object
try:
    textLCD = TextLCD()
except RuntimeError as e:
    print(("Runtime Exception: %s" % e.details))
    print("Exiting....")
    exit(1)

#Information Display Function
def DisplayDeviceInfo():
    try:
        isAttached = textLCD.isAttached()
        name = textLCD.getDeviceName()
        serialNo = textLCD.getSerialNum()
        version = textLCD.getDeviceVersion()
        rowCount = textLCD.getRowCount()
        columnCount = textLCD.getColumnCount()
    except PhidgetException as e:
        print(("Phidget Exception %i: %s" % (e.code, e.details)))
        return 1
    print("|------------|----------------------------------|--------------|------------|")
    print("|- Attached -|-              Type              -|- Serial No. -|-  Version -|")
    print("|------------|----------------------------------|--------------|------------|")
    print(("|- %8s -|- %30s -|- %10d -|- %8d -|" % (isAttached, name, serialNo, version)))
    print("|------------|----------------------------------|--------------|------------|")
    print(("Number of Rows: %i -- Number of Columns: %i" % (rowCount, columnCount)))

#Event Handler Callback Functions
def TextLCDAttached(e):
    attached = e.device
    print(("TextLCD %i Attached!" % (attached.getSerialNum())))

def TextLCDDetached(e):
    detached = e.device
    print(("TextLCD %i Detached!" % (detached.getSerialNum())))

def TextLCDError(e):
    source = e.device
    print(("TextLCD %i: Phidget Error %i: %s" % (source.getSerialNum(), e.eCode, e.description)))

#Main Program Code
try:
    textLCD.setOnAttachHandler(TextLCDAttached)
    textLCD.setOnDetachHandler(TextLCDDetached)
    textLCD.setOnErrorhandler(TextLCDError)
except PhidgetException as e:
    print(("Phidget Exception %i: %s" % (e.code, e.details)))
    print("Exiting....")
    exit(1)

print("Opening phidget object....")

try:
    textLCD.openPhidget()
except PhidgetException as e:
    print(("Phidget Exception %i: %s" % (e.code, e.details)))
    print("Exiting....")
    exit(1)

print("Waiting for attach....")

try:
    textLCD.waitForAttach(10000)
except PhidgetException as e:
    print(("Phidget Exception %i: %s" % (e.code, e.details)))
    try:
        textLCD.closePhidget()
    except PhidgetException as e:
        print(("Phidget Exception %i: %s" % (e.code, e.details)))
        print("Exiting....")
        exit(1)
    print("Exiting....")
    exit(1)
else:
    DisplayDeviceInfo()

display_tweet = []

try:
    if textLCD.getDeviceID()==PhidgetID.PHIDID_TEXTLCD_ADAPTER:
        textLCD.setScreenIndex(0)
        textLCD.setScreenSize(TextLCD_ScreenSize.PHIDGET_TEXTLCD_SCREEN_2x8)

    for tweet in stream:
        if 'text' in tweet:
            text = tweet['text']
            if type(text) == str:
                if SEARCHTERM in text.lower():
                    display_tweet.append(text)
            if display_tweet:
                item = display_tweet.pop()

                textLCD.setBacklight(True)
                print(item)
                row1 = item[:20]
                row2 = item[20:40]
                print("Writing to first row....")
                textLCD.setDisplayString(0, row1)
                print("Writing to second row....")
                textLCD.setDisplayString(1, row2)
                sleep(2)

                print("Turn on cursor....")
                textLCD.setCursor(True)
                sleep(2)

                print("Turn on cursor blink....")
                textLCD.setCursor(False)
                textLCD.setCursorBlink(True)
                sleep(2)

            print("No Tweets")
            textLCD.setBacklight(False)
            textLCD.setCursorBlink(True)
            textLCD.setDisplayString(0, "")
            textLCD.setDisplayString(1, "")
        if len(display_tweet) > 100:
            break

except PhidgetException as e:
    print(("Phidget Exception %i: %s" % (e.code, e.details)))
    print("Exiting....")
    exit(1)

textLCD.setDisplayString(0, "")
textLCD.setDisplayString(1, "")
textLCD.setBacklight(False)

try:
    textLCD.closePhidget()
except PhidgetException as e:
    print(("Phidget Exception %i: %s" % (e.code, e.details)))
    print("Exiting....")
    exit(1)
