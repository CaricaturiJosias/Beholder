import requests

def set_request():
    return(f"http://localhost:80")
def main():
    with open('/home/cezario/Dev/Beholder/bhldr.registerInfo.req.xml', 'r') as file:
        soap_message = file.read()
    print(soap_message)
    url = "http://localhost:8081"
    headers = {
        'Content-Type': 'text/xml',
        'SOAPAction': 'http://www.example.com/webservice/registerInfo',  # Replace with your SOAPAction
    }
    response = requests.post(url, data=soap_message, headers=headers)
    # Check the response
    if response.status_code == 200:
        print("SOAP request sent successfully.")
        print(response.content)  # This will contain the response from the API
    else:
        print(f"Error: {response.status_code} - {response.text}")
if __name__ == "__main__":
    main()
