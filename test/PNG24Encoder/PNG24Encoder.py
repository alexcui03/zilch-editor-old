from PNGEncoder import PNGEncoder
from ByteArray import ByteArray

class PNG24Encoder(PNGEncoder):
    def __init__(self):
        pass
    
    @staticmethod
    def encode(image, filter = 0):
        if image == None:
            raise TypeError('2007:image')
        if filter < 0 or filter > 4:
            raise ValueError('2008:filter')
        return PNG24Encoder.__encode(image, filter)

    @staticmethod
    def __encode(image, filter:int):
        transparent = False
        width = 960
        height = 720
        result = ByteArray()
        PNG24Encoder.writeSignature(result)
        PNG24Encoder.writeIHDR(result, width, height, 0x08, 0x06 if transparent else 0x02)


