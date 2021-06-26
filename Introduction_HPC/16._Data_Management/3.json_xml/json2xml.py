#!/usr/bin/env python3

import json

data=json.load(open('crystals.json'))

wf=open("crystals.xml",'w')

wf.write("<STRUCTURES>\n")
for i in data:
    wf.write("   <CRYSTAL>\n")
    wf.write("      <FORMULA>%s</FORMULA>\n" % i['formula'])
    wf.write("      <ENERGY_PA>%s</ENERGY_PA>\n" % i['energy_pa'])
    wf.write("      <BAND_GAP>%s</BAND_GAP>\n" % i['band_gap'])
    wf.write("   </CRYSTAL>\n")    
wf.write("</STRUCTURES>\n")
wf.close()

