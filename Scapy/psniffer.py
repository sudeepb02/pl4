from scapy.all import *
import multiprocessing
import os,sys,time
import threading

def display(pkt):
    pkt.show()

#Worker function 
def worker(i):

   	print threading.currentThread().getName(), 'Capturing packets'
	sniff(filter=i,prn=display, count=2)
    	time.sleep(2)
    	print threading.currentThread().getName(), 'Successfully captured packets'

print("1.Capture TCP Packets\n2.Capture UDP packets")
choice = raw_input("Please select your choice : ")

if choice==1:
	t1 = threading.Thread(name='CORE1', target=worker,args=("tcp",))
	t1.start()
elif choice==2:
	t2 = threading.Thread(name='CORE2', target=worker,args=("udp",))
	t2.start()
else:
	print("Please enter correct choice :")

while True:
	continue	
