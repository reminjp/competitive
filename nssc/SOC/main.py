import base64
import csv
import re
import subprocess

employeelist = []
maillog = []

with open('employeelist.csv') as f:
    reader = csv.reader(f)
    employeelist = [row for row in reader][1:]

with open('maillog.csv') as f:
    reader = csv.reader(f)
    maillog = [row for row in reader][1:]

mail_address_set = set()
r = re.compile(r'請求書[0-9]+\.zip')

for row in maillog:
    s = row[3]
    s = s.replace('=?ISO-2022-JP?B?', '')
    s = s.replace('?=', '')
    s = base64.b64decode(s)
    s = s.decode("iso-2022-jp")
    if r.match(s):
        mail_address_set.add(row[2])

employee_ids = []

for row in employeelist:
    if row[2] in mail_address_set:
        employee_ids.append(row[0])

print('flag{{{}}}'.format('_'.join(employee_ids)))
# flag{101_106_108}
