#pip install pyshark==0.3.7.6
import pyshark

capture = pyshark.LiveRingCapture(interface='en0')
capture.set_debug()
for packet in capture.sniff_continuously():
    print('.')
