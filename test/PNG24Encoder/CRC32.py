from ByteArray import ByteArray
from Integer import UINT32

class CRC32(object):
    def __init__(self):
        self._TABLE = CRC32.InitTable()

    @staticmethod
    def InitTable():
        mem = ByteArray(1024)
        for i in range(256):
            c = i
            for _ in range(8):
                if (c & 1) == 1:
                    c = 0xEDB88320 ^ (c >> 1)
                else:
                    c >>= 1
            mem.si32(c, i << 2)
        return mem
    
    @staticmethod
    def hashBytes(data:ByteArray):
        if len(data) > 0:
            length = len(data) + 1024
            mem = ByteArray()
            mem.writeByteArray(CRC32.InitTable())
            mem.writeByteArray(data)
            if len(mem) < 1024:
                mem += [0] * (1024 - len(mem))
            c = UINT32.convert(-1)
            i = 1024
            c = mem.li32((((c ^ mem.li8(i)) & 0xff) << 2)) ^ (c >> 8)
            i += 1
            while i < length:
                c = mem.li32((((c ^ mem.li8(i)) & 0xff) << 2)) ^ (c >> 8)
                i += 1
            return c ^ 0xffffffff
        else:
            return 0