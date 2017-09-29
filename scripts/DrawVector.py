#!/usr/bin/python

import matplotlib.pyplot as pyplot
import sys, os
import struct
import binascii

# Test for int type
def drawVector(drawingType, path, cmd, figName):

  x = []
  y = []
  pathVector = path + "/tempVector.data"

  #--------------------------------------
  if (drawingType != 5) and (drawingType != 6) and (drawingType != 7) and (drawingType != 8):

    # Int16
    if (drawingType == 1):

      # Read Data
      with open(pathVector, "rb") as f:
        while 1:
          # convert string to hex
          byte1_s = f.read(1)
          byte2_s = f.read(1)
          byte_s = binascii.hexlify(byte2_s + byte1_s)
          if not byte_s:
            break
          x.append(int(byte_s, 16))

    # Int32
    if (drawingType == 2):

      # Read Data
      with open(pathVector, "rb") as f:
        while 1:
          # convert string to hex
          byte1_s = f.read(1)
          byte2_s = f.read(1)
          byte3_s = f.read(1)
          byte4_s = f.read(1)
          byte_s = binascii.hexlify(byte4_s + byte3_s + byte2_s + byte1_s)
          if not byte_s:
            break
          x.append(int(byte_s, 16))

    # Float
    if (drawingType == 3):

      # Read Data
      with open(pathVector, "rb") as f:
        while 1:
          byte1_s = f.read(1)
          byte2_s = f.read(1)
          byte3_s = f.read(1)
          byte4_s = f.read(1)
          byte_s = byte4_s + byte3_s + byte2_s + byte1_s
          if not byte_s:
            break
          tmp = binascii.hexlify(byte_s)
          tmp = binascii.unhexlify(tmp)
          tmptmp = struct.unpack('!f', tmp)
          x.append(tmptmp)

    # Double
    if (drawingType == 4):

      # Read Data
      with open(pathVector, "rb") as f:
        while 1:
          byte1_s = f.read(1)
          byte2_s = f.read(1)
          byte3_s = f.read(1)
          byte4_s = f.read(1)
          byte5_s = f.read(1)
          byte6_s = f.read(1)
          byte7_s = f.read(1)
          byte8_s = f.read(1)
          byte_s = byte8_s + byte7_s + byte6_s + byte5_s + byte4_s + byte3_s + byte2_s + byte1_s
          if not byte_s:
            break
          tmp = binascii.hexlify(byte_s)
          tmp = binascii.unhexlify(tmp)
          tmptmp = struct.unpack('>d', tmp)[0]
          x.append(tmptmp)

    # Plot pyplot
    pyplot.title("")
    pyplot.rcParams.update({'font.size': 10})
    pyplot.plot(x, color='green', linestyle='solid', linewidth=1, label='data')
    pyplot.grid()
    if (cmd == 0):
      pyplot.show()
    else:
      figName = path + '/' + figName + '.png'
      pyplot.savefig(figName, dpi=96)
    pyplot.close()

  #--------------------------------------
  # Cplx Int16
  if (drawingType == 5):

    # Read Data
    with open(pathVector, "rb") as f:
      while 1:
        byte1_s = f.read(1)
        byte2_s = f.read(1)
        byte3_s = f.read(1)
        byte4_s = f.read(1)
        byteI_s = byte2_s + byte1_s
        byteQ_s = byte4_s + byte3_s
        if not byteI_s:
          break
        tmpI = binascii.hexlify(byteI_s)
        x.append(int(tmpI, 16))

        tmpQ = binascii.hexlify(byteQ_s)
        y.append(int(tmpQ, 16))


    # Plot pyplot
    if (cmd == 2):
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.plot(x, y, color='green', linestyle='solid', linewidth=1, label='data')
      pyplot.grid()
      pyplot.show()
      pyplot.close()
    else:
      pyplot.figure(1)
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.subplot(211)
      pyplot.plot(x, color='green', linestyle='solid', linewidth=1, label='I')
      pyplot.grid()
      pyplot.subplot(212)
      pyplot.plot(y, color='green', linestyle='solid', linewidth=1, label='Q')
      pyplot.grid()
      if (cmd == 0):
        pyplot.show()
      else:
        figName = path + '/' + figName + '.png'
        pyplot.savefig(figName, dpi=96)
      pyplot.close()

  #--------------------------------------
  # Cplx Int32
  if (drawingType == 6):

    # Read Data
    with open(pathVector, "rb") as f:
      while 1:
        byte1_s = f.read(1)
        byte2_s = f.read(1)
        byte3_s = f.read(1)
        byte4_s = f.read(1)
        byte5_s = f.read(1)
        byte6_s = f.read(1)
        byte7_s = f.read(1)
        byte8_s = f.read(1)
        byteI_s = byte4_s + byte3_s + byte2_s + byte1_s
        byteQ_s = byte8_s + byte7_s + byte6_s + byte5_s
        if not byteI_s:
          break
        tmpI = binascii.hexlify(byteI_s)
        x.append(int(tmpI, 16))

        tmpQ = binascii.hexlify(byteQ_s)
        y.append(int(tmpQ, 16))


    # Plot pyplot
    if (cmd == 2):
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.plot(x, y, color='green', linestyle='solid', linewidth=1, label='data')
      pyplot.grid()
      pyplot.show()
      pyplot.close()
    else:
      pyplot.figure(1)
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.subplot(211)
      pyplot.plot(x, color='green', linestyle='solid', linewidth=1, label='I')
      pyplot.grid()
      pyplot.subplot(212)
      pyplot.plot(y, color='green', linestyle='solid', linewidth=1, label='Q')
      pyplot.grid()
      if (cmd == 0):
        pyplot.show()
      else:
        figName = path + '/' + figName + '.png'
        pyplot.savefig(figName, dpi=96)
      pyplot.close()

  #--------------------------------------
  # Cplx Float
  if (drawingType == 7):

    # Read Data
    with open(pathVector, "rb") as f:
      while 1:
        byte1_s = f.read(1)
        byte2_s = f.read(1)
        byte3_s = f.read(1)
        byte4_s = f.read(1)
        byte5_s = f.read(1)
        byte6_s = f.read(1)
        byte7_s = f.read(1)
        byte8_s = f.read(1)
        byteI_s = byte4_s + byte3_s + byte2_s + byte1_s
        byteQ_s = byte8_s + byte7_s + byte6_s + byte5_s
        if not byteI_s:
          break
        tmpI = binascii.hexlify(byteI_s)
        tmpI = binascii.unhexlify(tmpI)
        I = struct.unpack('!f', tmpI)
        x.append(I)

        tmpQ = binascii.hexlify(byteQ_s)
        tmpQ = binascii.unhexlify(tmpQ)
        Q = struct.unpack('!f', tmpQ)
        y.append(Q)

    # Plot pyplot
    if (cmd == 2):
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.plot(x, y, color='green', linestyle='solid', linewidth=1, label='data')
      pyplot.grid()
      pyplot.show()
      pyplot.close()
    else:
      pyplot.figure(1)
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.subplot(211)
      pyplot.plot(x, color='green', linestyle='solid', linewidth=1, label='I')
      pyplot.grid()
      pyplot.subplot(212)
      pyplot.plot(y, color='green', linestyle='solid', linewidth=1, label='Q')
      pyplot.grid()
      if (cmd == 0):
        pyplot.show()
      else:
        figName = path + '/' + figName + '.png'
        pyplot.savefig(figName, dpi=96)
      pyplot.close()

  #--------------------------------------
  # Cplx Double
  if (drawingType == 8):

    # Read Data
    with open(pathVector, "rb") as f:
      while 1:
        byte1_s = f.read(1)
        byte2_s = f.read(1)
        byte3_s = f.read(1)
        byte4_s = f.read(1)
        byte5_s = f.read(1)
        byte6_s = f.read(1)
        byte7_s = f.read(1)
        byte8_s = f.read(1)
        byteI_s = byte8_s + byte7_s + byte6_s + byte5_s + byte4_s + byte3_s + byte2_s + byte1_s
        byte1_s = f.read(1)
        byte2_s = f.read(1)
        byte3_s = f.read(1)
        byte4_s = f.read(1)
        byte5_s = f.read(1)
        byte6_s = f.read(1)
        byte7_s = f.read(1)
        byte8_s = f.read(1)
        byteQ_s = byte8_s + byte7_s + byte6_s + byte5_s + byte4_s + byte3_s + byte2_s + byte1_s
        if not byteI_s:
          break
        tmpI = binascii.hexlify(byteI_s)
        tmpI = binascii.unhexlify(tmpI)
        I = struct.unpack('>d', tmpI)[0]
        x.append(I)

        tmpQ = binascii.hexlify(byteQ_s)
        tmpQ = binascii.unhexlify(tmpQ)
        Q = struct.unpack('>d', tmpQ)[0]
        y.append(Q)

    # Plot pyplot
    if (cmd == 2):
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.plot(x, y, color='green', linestyle='solid', linewidth=1, label='data')
      pyplot.grid()
      pyplot.show()
      pyplot.close()
    else:
      pyplot.figure(1)
      pyplot.title("")
      pyplot.rcParams.update({'font.size': 10})
      pyplot.subplot(211)
      pyplot.plot(x, color='green', linestyle='solid', linewidth=1, label='I')
      pyplot.grid()
      pyplot.subplot(212)
      pyplot.plot(y, color='green', linestyle='solid', linewidth=1, label='Q')
      pyplot.grid()
      if (cmd == 0):
        pyplot.show()
      else:
        figName = path + '/' + figName + '.png'
        pyplot.savefig(figName, dpi=96)
      pyplot.close()


if __name__ == '__main__':
  try:
    vectorType = sys.argv[1]
    path = sys.argv[2]
    cmd = sys.argv[3]
    figName = sys.argv[4]
  except:
    vectorType = None
    path = None
  if not vectorType:
    vectorType = 1
  if not cmd:
    cmd = 0
  if not figName:
    figName = ""
  if not path:
    path = "/tmp/.CTPP/tempVector.data"
  drawVector(int(vectorType), path, int(cmd), figName)