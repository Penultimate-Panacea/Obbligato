#import mingus.core.notes as notes
equivalentTones = {'0': 'A0', '1': 'A0#', '2': 'B0', '3': 'C1', '4': 'C1#', '5': 'D1', '6': 'D1#', '7': 'E1', '8': 'F1',
                   '9': 'F1#', 'A': 'G1', 'B': 'G1#', 'C': 'A1', 'D': 'A1#', 'E': 'B1', 'F': 'C2', 'G': 'C2#', 'H': 'D2',
                   'I': 'D2#', 'J': 'E2', 'K': 'F2', 'L': 'F2#', 'M': 'G2', 'N': 'G2#', 'O': 'A2', 'P': 'A2#', 'Q': 'B2',
                   'R': 'C3', 'S': 'C3#', 'T': 'D3', 'U': 'D3#', 'V': 'E3', 'W': 'F3', 'X': 'F3#', 'Y': 'G3', 'Z': 'G3#',
                   'a': 'A3', 'b': 'A3#', 'c': 'B3', 'd': 'C4', 'e': 'C4#', 'f': 'D4', 'g': 'D4#', 'h': 'E4', 'i': 'F4',
                   'j': 'F4#', 'k': 'G4', 'l': 'G4#', 'm': 'A4', 'n': 'A4#', 'o': 'B4', 'p': 'C5', 'q': 'C5#', 'r': 'D5',
                   's': 'D5#', 't': 'E5 ', 'u': 'F5', 'v': 'F5#', 'w': 'G5', 'x': 'G5#', 'y': 'A5', 'z': 'A5#', '!': 'B5',
                   '<': 'C6', '#': 'C6#', '$': 'D6', '%': 'D6#', '&': 'E6', '>': 'F6', '(': 'F6#', ')': 'G6', '*': 'G6#',
                   '+': 'A6', ',': 'A6#', '-': "B6", '.': 'C7', '/': 'C7#', '[': 'D7', '?': 'D7#', ']': 'E7', '^': 'F7',
                   '_': 'F7#', '`': 'G7', '{': 'G7#', '|': 'A7', '}': 'A7#', '~': 'B7', '@': 'C8', '\\': 'RE'}
equivalentTimes = {'0': '64', '1': '32', '2': '16', '3': '8', '4': '4', '5': '2', '6': '1', '7': '0', '8': 'triplet',
                   '9': 'grace'}
# 64=1/64 note 32=1/32 note 16=1/16th note 8=1/8th note 4=1/4th note 
# 2=1/2 note 1=whole note 0= 2 tied whole 8=triplet 9=grace note


def readtones():
    """ Reads tones from solid stream of Base89 in a .txt file """
    toneList = []
    with open("testOutputTone.txt") as f1:
        while True:
            c1 = f1.read(1)
            if not c1:
                print("File read complete.")
                f1.close()
                break
            toneList.append(equivalentTones[c1])
    return toneList


def readtimes():
    """ Reads times from solid stream of Base10 in a .txt file """
    timeList = []
    with open("testOutputTime.txt") as f2:
        while True:
            c2 = f2.read(1)
            if not c2:
                print("File read complete.")
                f2.close()
                break
            timeList.append(equivalentTimes[c2])
    return timeList

times = readtimes()
tones = readtones()
