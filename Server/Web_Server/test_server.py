import requests
r = requests.post('localhost:5000',data={'number': 12524, 'type': 'issue', 'action': 'show'})
