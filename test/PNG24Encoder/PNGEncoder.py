from CRC32 import CRC32
from ByteArray import ByteArray

class PNGEncoder(object):
    def __init__(self):
        self._TMP = []
    
    @staticmethod
    def writeSignature(mem:ByteArray):
        mem.writeUnsignedInt(0x89504E47)
        mem.writeUnsignedInt(0x0D0A1A0A)

    @staticmethod
    def writeChunk(mem:ByteArray, chunk:ByteArray):
        mem.writeUnsignedInt(len(chunk) - 4)
        mem.writeByteArray(chunk)
        mem.writeUnsignedInt(CRC32.hashBytes(chunk))

    @staticmethod
    def writeIHDR(mem:ByteArray, width:int, height:int, bits:int, colors:int):
        chunk = ByteArray()

        chunk.writeUnsignedInt(0x49484452)
        chunk.writeUnsignedInt(width)
        chunk.writeUnsignedInt(height)
        chunk.writeByte(bits)
        chunk.writeByte(colors)
        chunk.writeByte(0x00)
        chunk.writeByte(0x00)
        chunk.writeByte(0x00)

        PNGEncoder.writeChunk(mem, chunk)

        
    


