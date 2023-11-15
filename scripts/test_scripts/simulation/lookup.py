#!/usr/bin/python3
import requests, re
from time import sleep
import xml.etree.ElementTree as ET

url = "http://localhost:12332"

# headers
headers = {
    'Content-Type': 'text/xml; charset=utf-8'
}

# def print_dam():
#     print("""
# ..........::::...:::::::...........:::....::::::::::::::::::::::::::::........::::::::::::::::::::::::::::::::::::---------------------------::::::--::--::::::::::::::::::::::::-------::::::::-::::::::::::.....:::::::::::.
# ..........:::::::::::::-:..::::....::...........::::::::::---:::::::::::::::::::::...:::.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::..::::---:::.
# .............:::::::::::::::::::::-:::::::::::::.......::..::::::::::::::-----:-------------:::::::::::::::::::::---::----:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.
# ....................:::::::::::---:::::::::::::::::::::........:...:.....::::::.::::::::::::::::::::::::::::--:::::----:----::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.::::.
# ..:::.................::::::::::::::::::::::::::----::::::::::::::::::::....:......:......:::------------------::...::....::::::----------------------------------------:::::::.::::::::::::::::::::::::::::::--:::::.:::::::.
# ......:::...............:::::::::::::::::::::::::::::::-----::::::-------::::::::::.....:::::::::----::=#%#=:---:::::::::::::::------------------------:::::--::--------------------:----::...+#*.:::::::::::::::....:::......
# ..........:.........................::.:::::::::::::::::::::::::--::::::::::::-:::::::::--:::.-#@@@@@@@@@@@@@@=-----------:::---::.:::::::......:..::--:.:::::::-----:---::-----::::.:--:.:-:=@@@+:...::.::-+*#%\%##*=-:-#%*::.
# ...........:::::::::..........:.........::.......::.....::::::::..:::::::::::--:::::--::-=@@@@@@@@@@@@@%+-*@@@@@%=:::::---::.:.+*+-:.::::.:::.:-+*#%@@@@@@@%*++-+=-:---:-=@@@@@#+-:=#@@%+=++=#@#@@--+#%\%\%@%+--=----==:-+@@@=:.
# .....:.........::::::::::::::.:+#+::.:::-=-::.:...:-==+%@%=:.....:::.=@@@@@@@@@@@@@@@@@@@@@@@@@@*+*+-+--:-::-#@@@@@@#:.::.-+@@@@%@-+%\%#*--#@%\#%@@@@@@@@@@@@@@@@###@@@#-=%@@@@@@@@@@@@=#@@@@@@@@+@@=@@@@@%*\%\%=*##++:*--*@@*@%-.
# ..............::::::.::::::::::@#@::::::*+#..-+*@@@##@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-:==--=+%*+=:::-#@#=-%@@@@@@@@@@@@@%==@@@@@@@@@@@@@@@@@@%+:--+==#@@@@@@@@@@@@@@*=+*#@@@@@@#@%@@@@@@%=@@@@@%\#%\%##@@@%@%@@@@@@@#*@@@.
# ...::::::-=**+*+=*@@#==+*==+=-=@-@#%=--#@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@=::..::::...:..:::::=-=....:+%\%#+-.-+-*=-==:+@@@@@@@@%\%@#@@@@%\#%@@@@+*%\%#+-------+**#++#@@%*=*@@@#====+++#*+=@@@%-=**=--.@@@*:--=#@%\%@@@@@#-=#@@#.-#@@.
# .%*#@@@@@@@@@@@@@@%\%##**###%@@@@#@@@@@@@@@@@@@@@@*#@@%\%@@+-.:::::::::::..........:.......::-=-:::....:=+**#@@@*====+=--===---+@@@+==--====-=----..:::-:.:==:==-:-----::--.---:::..::#=%+....::-:%=*:.....::=*%@@%\%###*+-..-=+.
# .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@==#=====--:..:::::.:::...:...............:....................:-=+++=--::-=-:-=--:......:::----::::---:-----=----:--::--==--::..::-----:--:-@=@-:....--.%=#-==-:::::.----+##+==.:--:-.
# .@@@@++#*+*##*++#%@@@@@@@@@@%*=%@@@@@@@@%=%-.::::-:--------------:::::--------::::..............::.-=--::::...............:.......-=:-========-:::-::::----====-----:-.:-:::::-::--#@@@+%@@%\%*=.++=:--=.::::.-:-::::--:-:-:::.
# .-----------:---+@@@@@@@@--*#@@@@@@@@@@@@@@@%-::::#@@#-.::::::.:::::..::::::#@%=:::---::..::.::-+*++=++%@@*+==+=--=----::-====--:-+=++*+==-.:.---:----------=+++*+##%\%+:-:.-:::::--@@@@*@@%+*#+:===@@@%#\####%#\##%\%\%+=:.-:--::.
# .-::::-::.:.:.:-@@@@@@@@@-=+=@@@%@@@@@@@@@@@@=-==+@@%@@@@@@@@@@@%++++++*#%@@@@@@@@%###***###%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@#%@=.--@@@@@@%@@@@@%@@@@%*=:=---:-.
# .:..--:::::::::#@@@@%\%@@@@@@@@@+@@@@@#@@%@+@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#@-@@%@+-*%@@-.-=@@@%@#++==-#+#+-@#+=--.:---.
# .@@@@@@@@@@@@@@@@@@@@@@@+@@@%-@@@@@@@@@@@@@@#+==@#@@+@@@@@@@@@%=#%=-*+##:=+=--=-@@#+=--=-%@%\%\%*@#+%@@@@@+@%@@@@@@@%\%#+::-#@@@@@@@@@@@@@@@@@@@@@@@@@*--+-%@@@@@@@@@@@@@@@@@@@@@@@@@@@%#@@@@@@@@=::-+@@@@@@@@@@@@@@@@%*=--.:--:.
# .#####+*#%@@@@@%\#%@@@@@@@@@@@@@@@@@@@@%-\%@@@@@@@@@@@@@@@@@@#.=#*:%@@@@@@@@@@@%@@@@@@@%#\%@%=*%@@@@@@@@@@@@@@@@@@@@%*\%\%=---@@@%@@@@@@@@##@@@@@@@%##@@@--%@@@@@@@@@@@@@@%@@@@@@@++@@#+==:#@@@@@#+=-:--*##==#@@@%*++#%*-.:::::-.:.
# .:---=+##==-:+%#=#:+=+====-=+@#=-.-*%\%#=@@==--*%\+%*:-@%==:##+=##:@@+=:#%===@*-*@%=+#=---@@--%@@=*++===@%-#@@:#**++++@%#:*@@%###*#*+@%=.#@#%\%\%\%#\#%\%@@=-@@@%\%\%\%\%\%\%\%\%@#+=+%\%\%@@@@@@#***+::--=+*#+=-:=--==-:---------::--::::--:..
# .=++===:+==++#:+==++=-::..=#@@+--::-@@=%@@=--===+@+:#@#+:-=++@@=:@@*--=**+%@=:@@%-==++++@@-=@@-==++===@@++@@-+***+++@%\%-+@@#%##***+@@--%@*#%\%\%\%#=-@@*-%@@#%\%\%\%\%*-+@+:-%@%\%\%\%#\#%+-##*#+==:=#++==---=---.:::-----:.:::::-:.::-..
# .#*%\%+-:++#%+=@%=---==---=%-@@=---::@@-@@@=-=-==%@=-%@+----==@@--@@*-=-==-@@:-@@*-=-=--=@@-:@@:=--=--=@@==@@---=====@@#--@@------=+@@==@@*#+===#@@@@%+\%@@*=====#%+@*+##@#=-===+#%+#=%+==::+%#=--==+----.::-.:--:::::::::-::::.
# .=--=+-=++*+@@-+=:=+*=-=-%#@@#-=:-:-@@:%@@==+--=@%-*@@=.=----@@-=@@+-=----@@::@@=+--=:--@@-+@@-=:--:-=@%++@@:----::-@@+=#@#:--:::==@#--@#=+====**-@@%=#@@#-===-++-@*+.=%#=-=--++==*-#:=+-:---==-=-+--:-::----:::.:::::::-.:-:.
# .==-=+===+#@*-==-==-.::-##=@@===---#@%-=@@-*+===%#=+@@==*---:@@-=@@===--:-@@==@@-*-:=:-=@%-*@@=-.-.:--%#--@@:=-=--:-@@=+%@=::-::.==@#--@#=*====*+-@@%=*#@%---====-@##==%\%-----===+==#-+#=.--::-=++=-:--.-=-:---::::--.::::=+=.
# .:-=+=----=-#*--==---:-++=+@@-.-=--@@-+@@*@@@@@@++#@@%\%@@@@@@@%*\%@@@@@@@@@#+%@@@@@@@@@@%*\%@@@@@@@@@@@@*+++@@%@@@@@@@@@#*@@+@@@@@@@@#+*+%==#@@@@@%#\#%#-=-@@@@@@@%#+@=*==##+#%\%#**+#:===:++---::-.--=-::::--.--:..::.------+*==.
# .=+=:=====+#+----.:::-==--*@@-==-::@@+=+@@@@@@@@*===+@@@@@@@@=#@+@@@@@@@@@@+==+@@@@@@@@@%*\%##@@@@@@@@@%=**-@@@@@@@@@@+@@#%@@@@@@@@@#+**+@@@@@@@#+#%-++*@@@@@@@%\%##=#%++=++##%\%\#%\#%\%+-=-==--====-:.::-----:.-----:-:----=*%+=-.
# .=--=+==++=-=+=-:-=-:==--:@@==-----%#=@@@@@@@@@@@==@@@@@@@@@@@#-@@@@@@@@@%@%=%@@@@@@@@@@@=-@@@@@@@@@@@@%-=@@@@@@@@@@@@-=@@@@@@@@@@@@@*+@@@@@@@@@@@@@#*+@@@@@@@@@###@+++=#@#**#%@@@@@%---=:-======--=-::-======++==-:-:-=+==+:.
# .--++=-+=:----::-=---==:-#%*#*+=-=*+#@@@%:-==%*@@*@@@@@@-%@+@@=@@@@*=-%@*@@#%@@@*====#=@@-+@@@@-+=-+@@@@*%@@@#-=-:*@@@+=@@@@@###%@@@@=-@@@+%@@@@@@@@@=+@@#@@@@@@@@@@%=+@@@@@@@@@@@@@@-==---:--======----=-----=-==----=+==+=:.
# .----==--=:::-.-++-==--=%@-=+==-=#+-@@@#=-==@@%@@@@@#@#-@@@#@@+@@@+==@@#=@@-@@@+=+++@@#@@=@@@#+#%**@@@@@+@@@#+*+==##@@=@@@=++*#*=@#@@:%@@==+*##*+++@@-@@@+*++++#%##@@=+@@@@@@@%*+--@@@==----=--=-=---:.:--.----:-----=:+====-.
# .-==+=-=+=:::------=---+%-#-+=:-+*+@@@%=-=-@@#@@=@@%\%#-@@@%#@@@@@*-=#@@*#@@#@@#====#@%\%@@+@@#%=%*+*@#@@#=@@%+#*#++%\%@@-@@@##+#*#+@*@@:@@@==+++*###+@@=@@%\#%\%\%@@@@%#@@=:@@+:+--:-++++@@----:--+-+-:::-:-------=:=:--------+--:.
# .-+*=-+#-+-:--=--=+----==*-++-===+@@@@=-+-#@=#@@@@@%\%=+@@=@#@#@@%+-=@@+=%@%@@@+---=%@+#@@@@@+#*%==#@+@@-#@@#=*=*++%\%@@+@@=+#+#=#+@*@@=@@@======++++@@%@@*#%\%\%\%\%\%##*@@@-@@-:+=---=+==@@#:::.:--=.=-:---===+=:.+:=-----:::---:..
# .-#+++#=+=-====:-.-====::-+=:=@@@@@@@@##+-#*+@@@@@@@#-#@@@@@@@@@*--=%#=-%@@@@@=:::-#++%@@@@%#=#+--#*:@@#@@@*-=-+=+*+@@@@@--*-*:*#@=@@+@@@-==------=%@@@@+**++++++===@@=@@=-=+-=-=+=-+@@-:.:---:+==:-::=+--==-=-=-----:::::---.
# .-+++==.++=--==-=+#*+==+++:*@@@@@@@+:::-+%#\--%@@@@+-=#%*-=-#@@%=-:--+#%\%@@@@@+---=+#%@@@@@@##-####@@@@@@@@@#*###++*#@@@@@++#=+=+#@=@@@@@%:------::-+@@@%======------@@*@@+-=+:=--++--@@=:.::-:-=-=:::--+*#*+=--------:.--:::-.
# .-=*+++++====---++=---==-+%@@@@*+#@@@@@@@@@*====*%@@@@@@@#--=*####%@%*+=-#+-=+#*+*%\%##*-#+===++:--=-:+@@@@=--:---==:@@@@=+++-+=-*@@@@@@@+--======--=%@#=----:-++++==%@@@@=:-=---=++=-%@@#+------:-------=--:--==+--:-::..:.::.
# .-.--:--+*##+=-=-:::::-+%@@@*=++#@@%\#%@@@++=+#%@@@@@@@@#*++#%@@@%@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+#@@@@@@@@@@@@%\%\%\%#\#%#+*#*:+#@@@==++===++====---===--:--=++==*@@@+--=+#*==+=-=#@@@@@@@@@#=:--==:.:::::-::-------::----.
# .:--:.-::-:---::::--=*@@@@*==-=*#+==+%\%=+#-+*++**+*%@=#%==**##+++%\%+==-=++*#%\%\#*%@%**++*%\%###@@@@@@@%\%\%\#%\%\#%@@@@@@@@@@@@@@@@@@@@@@%##\###%\%\%\%\%\%\%\%#\#%\%\%\%#++++==+*+=====-=+===+**#%\%*=---=+*%@@@@@@@@@@@%+-::::-----====--::----.
# .:::--::-=+**+#@@@@@@@@@#+=--::--===-++##=:----==++#%@@*:-::-----=======:--==-==##-===+++===##=++%#-*#+*++=#*++++%=**+++*##*##%###***+***+++++==++=++++=-----==++======+*+=----======+===+++==:*@@@@@@@=::-----------::---:::.
# .@@@@@@@@@@@@@@@@#*+=--===++*#**#@@@%+-===-:::::.:-+*=---:--::.::-===--:.:---=-:=***=-.:-==:==++=*#@@*====:====--+===---==-==++-=+=+=======-=-----------:::-----=---------=----:--------::-==+==+++==@@+-:::::::..::..::::.:..
# .===------::-+#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#####*+=====+**++=---=--:-------=+=-----=+=:..:-=-:-::-=++=--.:---:-==+=:------------::::::..::::---:::-:::::::::::--:--::::::::::--===+#%@@@=-::.::::..::.......::.
# .%@@@@@@@@@@@@@@@%\%#\#%\%\%@@@@%\%\%\%*=--=+#%@@@@@@@@@@@@%#\%@@@@@%\%\%\%#**#%@@@@%#\##%@@@@%\%#**######%@@@@@@@@@@@@@%**#%\%#++\#%\%#+=-=--::-======----------------------:::::::::.....::::::::::::::::::--=-=+#@@+---::::.::.......:.::..
# .--::::----:::-::::::::::::::---------==+=====+*++*####%\%@@@%\%##\#%\%@%###\#%\%@@@@@%\%#########*+#%@@@@@@@@@@@@@@@%\%\%@@@@@@@@@@@@%\%\%\%####*+++==----=----=------------------::---------:--------::---===++==----:-:..:::..::::.:...
# ...::--::::...:...:::::::::--:::---====----::------=**+===+++++++*##++=+#%\%@@%*+=+*##%##*++##%#**###%\%@%\%\%\%@@@%#*+##+++#%@@@@@@@@@%\%##*+==---------------------::-:::::----------::----------------==+++=-----:.:::.::......:.
# .-------::::::::::::::::.....:::..::--==============-------:--=======***+==----==========-=++=-::-------==--==++++=======++*##%\%\%\%\%\%##*+=-------------------:::....:..:--::::-:...::::-::------------=+*##++==-:::::.......::.
# .:::---:.....:::--:::..::::::::----::..:--==---:--::::----::---======----:::::..:-::----=+++=--:------:::::::----=---:::---===++++++**++=--:::---------------::::::::.:::..:::.::::::::..:--------
#           """)

def generate_default_payload():
    return """
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
    xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
    xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    xmlns:bhldr="http://tempuri.org/bhldr.xsd">
 <SOAP-ENV:Body>
  <bhldr:lookup>"""

def end_payload(payload):
    return payload + \
"""</bhldr:lookup>
 </SOAP-ENV:Body>
</SOAP-ENV:Envelope>"""

def add_request(current_request, name):
    return current_request + \
f"""
    <input>
        <infoName>{name}</infoName>
        <timestamp></timestamp>
    </input>""" 

item_analog_list_n = [
    'P',
    'PF',
    'F',
    'Vv',
    'ED',
    'EPGen',
    'EFGen',
    'PFGen'
]

item_analog_list = [
    'P',
    'PF',
    'F',
    'ED',
    'EPGen',
    'EFGen',
    'PFGen'
]

item_digital_list_n = [
    'P_QC',
    'F_QC',
    'T',
    'Area_'
]


def increment_payload_n(payload, items, n):
    if n == 0:
        number = ""
    else:
        number = f"{str(n)}"

    for item in items:
        payload = \
            add_request(
                payload,
                (item + number))
    return payload

def parse_n_resp(response):
    data_list = {}
    for i in range(1,22):
        data_list[i] = []
    root = ET.fromstring(response.content)

    namespaces = {
        "SOAP-ENV":"http://schemas.xmlsoap.org/soap/envelope/",
        "bhldr" : "http://tempuri.org/bhldr.xsd"
    }
    data = root.find('.//SOAP-ENV:Body/bhldr:lookupResponse', namespaces=namespaces)
    for data_element in data.findall('data', namespaces=namespaces):
        info = data_element.find('infoName', namespaces=namespaces).text
        value = str(round(float(data_element.find('value', namespaces=namespaces).text),3))
        time = data_element.find('timestamp', namespaces=namespaces).text
        number = re.findall(r'\d+', info)
        if (number == []):
            if (data_list[6] == []):
                data_list[6].append(f"{time}")
            data_list[6].append(f"{info}: {value}")
        else:
            if (data_list[int(number[0])] == []):
                data_list[int(number[0])].append(f"{time}")
            data_list[int(number[0])].append(f"{info}: {value}")
    show_result(data_list)
    # print(response.content)

def show_result(data_list):
    #  6 on 6 items
    print(data_list[1][0])
    for i in range(1,len(data_list)):
        for j in range(1, len(data_list[i])):
            if (i < 10):
                print(" " + data_list[i][j], end="  ")
            else:
                print(data_list[i][j], end=" ")
        print("")


def simulationLoop():
    while (True):
        payload = generate_default_payload()

        for n in range(1,6):
            payload = increment_payload_n(payload, item_analog_list_n, n)
            payload = increment_payload_n(payload, item_digital_list_n, n)
        payload = increment_payload_n(payload, item_analog_list, 0)

        payload = end_payload(payload)
        try:
            response = requests.request("POST", url, headers=headers, data=payload)
            if (response.ok) :
                print("\033c", end="")
                parse_n_resp(response)
            else :
                print(f"Response not ok: {response.status_code}")
                print(response.content)
        except Exception as e:
            print(f"Error: {e}")
        sleep(1/100)

def main():
    try:
        simulationLoop()
    except KeyboardInterrupt:
        print('Interrupted')
main()

