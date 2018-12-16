from Integer import UINT32

class ByteArray(object):
    def __init__(self, size = 0):
        self.__array = [0] * size
    
    def __len__(self):
        return len(self.__array)

    def writeByteArray(self, data:ByteArray):
        self.__array += data.__array
    
    def writeByte(self, data:int):
        self.__array += data
    
    def writeUnsignedInt(self, data:int):
        if data < 0:
            data = UINT32.convert(data)
        self.__array += (data >> 24) & 0xff
        self.__array += (data >> 16) & 0xff
        self.__array += (data >> 8) & 0xff
        self.__array += data & 0xff

    def si8(self, data, addr):
        if addr >= len(self.__array):
            raise IndexError('Index out of range')
        self.__array[addr] = data & 0xff
    
    def si16(self, data, addr):
        if addr + 1 >= len(self.__array):
            raise IndexError('Index out of range')
        self.__array[addr] = (data >> 8) & 0xff
        self.__array[addr + 1] = data & 0xff
    
    def si32(self, data, addr):
        if addr + 3 >= len(self.__array):
            raise IndexError('Index out of range')
        self.__array[addr] = (data >> 24) & 0xff
        self.__array[addr + 1] = (data >> 16) & 0xff
        self.__array[addr + 2] = (data >> 8) & 0xff
        self.__array[addr + 3] = data & 0xff

    def li8(self, addr):
        if addr >= len(self.__array):
            raise IndexError('Index out of range')
        return self.__array[addr]

    def li16(self, addr):
        if addr + 1 >= len(self.__array):
            raise IndexError('Index out of range')
        return (self.__array[addr] << 8) \
            + self.__array[addr + 1]

    def li32(self, addr):
        if addr + 3 >= len(self.__array):
            raise IndexError('Index out of range')
        return (self.__array[addr] << 24) \
            + (self.__array[addr + 1] << 16) \
            + (self.__array[addr + 2] << 8) \
            + self.__array[addr + 3]


