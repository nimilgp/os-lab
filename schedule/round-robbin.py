from operator import itemgetter 

pservicing = 0 # servicing done for proc in curr quant
arr = []
procq = [] #actual queue for the process that the cpu currently knows about
doneq = []
T = 0

#get the proc details
count = int(input("enter number of proc: "))
quant = int(input("enter number of quant: "))
for i in range(count):
    print("pid:",i+1)
    at = int(input("enter at: "))
    bt = int(input("enter bt: "))
    pid = i + 1
    wt = 0
    tat = 0
    wl = bt #work left
    proc = {"pid":pid, "at":at, "bt":bt, "wt":wt, "tat":tat, "wl":wl}
    arr.append(proc)

arr = sorted(arr, key=itemgetter('at')) #sort based on arrival , mimicks real thing

print("\n")
print(arr)
print("\n")

while (len(arr) + len(procq)) > 0:
    for proc in arr:
        if proc["at"] == T:
            procq.append(proc)
            arr.pop(0)
    if len(procq) > 0:
        if(pservicing == quant):
            proc = procq[0]
            procq.pop(0)
            procq.append(proc)
            pservicing = 0
            continue
        #serve first proc in procq
        proc = procq[0]
        pservicing += 1 
        print(str(T)+":proc:"+str(proc["pid"]))
        proc["wl"] -= 1
        #something here
        if proc["wl"] == 0: #at completion time
            proc["wt"] = (T + 1) - proc["at"] - proc["bt"] 
            proc["tat"] = (T + 1) - proc["at"]
            doneq.append(proc)
            procq.pop(0)
            pservicing = 0
    else:
        print(str(T)+":IDLE")
    T += 1 #time moves forward by 1 unit

#print table
print("\n")
print("*****************************************************************************")
print("PROC\t\tARRIVAL\t\tBURST\t\tWAIT\t\tTURNAROUND")
print("*****************************************************************************")
for proc in doneq:
    print("{}\t\t{}\t\t{}\t\t{}\t\t{}\n".format(proc["pid"],proc["at"],proc["bt"],proc["wt"],proc["tat"]))
