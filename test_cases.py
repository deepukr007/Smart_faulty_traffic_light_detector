import requests
import time

ID = ["BN01" , "BN02" ,"BN03" , "BN04" ,"BN05" , "BN06" ,"BN07" , "BN08", "BN09","BN10","BN11","BN12",
     "BS01" , "BS02" ,"BS03" , "BS04" ,"BS05" , "BS06" ,"BS07" , "BS08", "BS09" ,
      "BE01","BE02","BE03",
      "BW01" , "BW02" ,"BW03" , "BW04" ,"BW05" , "BW06" ,"BW07" , "BW08", "BW09","BW10",
      ]
w_status="0"
http_status = 200

for i in ID:
    if( i == "BN01"):
        w_status="0"
    elif( i == "BS05"):
        w_status="0"
    elif( i == "BW07"):
        w_status="0"
    else:
        w_status="1"
    
  
    data= w_status+i
    print(data)
    url="https://api.thingspeak.com/update?api_key=CLWMS3L5DVOXKVOV&field1="+str(data)
    r=requests.get(url)
    http_status = r.status_code
    print(http_status)
    time.sleep(20) 
    

