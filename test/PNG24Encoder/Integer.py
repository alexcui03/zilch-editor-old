class UINT32(object):
    def __init__(self, data = 0):
        self.__int = int(UINT32.convert(data))
    
    @staticmethod
    def convert(data):
        return data if data > 0 else (0xffffffff ^ (0 - data)) + 1
    
    def __int__(self):
        return self.__int
    
    def __repr__(self):
        return str(self.__int)
    
    def lsh(self, v):
        self.__int <<= v
        self.__int &= 0xffffffff
    
    def rsh(self, v):
        self.__int >>= v

    def __eq__(self, b:UINT32):
        return self.__int == b.__int
    

