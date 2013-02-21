<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.4">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="1" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="7" fill="1" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="PaJa" color="12" fill="7" visible="yes" active="yes"/>
<layer number="101" name="Doplnky" color="5" fill="1" visible="yes" active="yes"/>
<layer number="102" name="Kola" color="11" fill="7" visible="yes" active="yes"/>
<layer number="103" name="Popisy" color="2" fill="8" visible="yes" active="yes"/>
<layer number="104" name="Zapojeni" color="6" fill="7" visible="yes" active="yes"/>
<layer number="110" name="wago-seda" color="7" fill="8" visible="yes" active="yes"/>
<layer number="111" name="wago-cervena" color="12" fill="8" visible="yes" active="yes"/>
<layer number="112" name="wago-zelena" color="2" fill="8" visible="yes" active="yes"/>
<layer number="113" name="wago-modra" color="1" fill="8" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="no" active="no"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="OrgLBR" color="13" fill="1" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="atmega8">
<description>&lt;b&gt;Atmel ATmega8, ATmega48, ATmega88, ATmega168: 8-bit AVR microcontrollers&lt;/b&gt;
&lt;p&gt;&lt;ul&gt;
&lt;li&gt;ATmega8, ATmega8L:&lt;br&gt;
28-pin PDIP, 32-lead TQFP and 32-pad QFN/MLF
&lt;li&gt;ATmega48, ATmega48V, ATmega88, ATmega88V, ATmega168, ATmega168V:&lt;br&gt;
 28-pin PDIP, 32-lead TQFP and 32-pad QFN/MLF (no 28-pad QFN/MLF!)
&lt;/ul&gt;&lt;/p&gt;
&lt;p&gt;&lt;b&gt;Doublecheck before using!&lt;/b&gt;&lt;/p&gt;</description>
<packages>
<package name="MLF32">
<description>&lt;b&gt;32M1-A&lt;/b&gt; Micro Lead Frame package (MLF)</description>
<wire x1="-2.35" y1="2.05" x2="-2.05" y2="2.35" width="0.254" layer="21"/>
<wire x1="-2.05" y1="2.35" x2="2.05" y2="2.35" width="0.254" layer="51"/>
<wire x1="2.05" y1="2.35" x2="2.35" y2="2.05" width="0.254" layer="21"/>
<wire x1="2.35" y1="2.05" x2="2.35" y2="-2.05" width="0.254" layer="51"/>
<wire x1="2.35" y1="-2.05" x2="2.05" y2="-2.35" width="0.254" layer="21"/>
<wire x1="2.05" y1="-2.35" x2="-2.05" y2="-2.35" width="0.254" layer="51"/>
<wire x1="-2.05" y1="-2.35" x2="-2.35" y2="-2.05" width="0.254" layer="21"/>
<wire x1="-2.35" y1="-2.05" x2="-2.35" y2="2.05" width="0.254" layer="51"/>
<circle x="-1.55" y="1.55" radius="0.15" width="0.254" layer="21"/>
<smd name="1" x="-2.35" y="1.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="2" x="-2.35" y="1.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="3" x="-2.35" y="0.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="4" x="-2.35" y="0.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="5" x="-2.35" y="-0.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="6" x="-2.35" y="-0.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="7" x="-2.35" y="-1.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="8" x="-2.35" y="-1.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="9" x="-1.75" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="10" x="-1.25" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="11" x="-0.75" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="12" x="-0.25" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="13" x="0.25" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="14" x="0.75" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="15" x="1.25" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="16" x="1.75" y="-2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="17" x="2.35" y="-1.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="18" x="2.35" y="-1.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="19" x="2.35" y="-0.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="20" x="2.35" y="-0.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="21" x="2.35" y="0.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="22" x="2.35" y="0.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="23" x="2.35" y="1.25" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="24" x="2.35" y="1.75" dx="0.7" dy="0.3" layer="1" roundness="50"/>
<smd name="25" x="1.75" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="26" x="1.25" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="27" x="0.75" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="28" x="0.25" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="29" x="-0.25" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="30" x="-0.75" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="31" x="-1.25" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<smd name="32" x="-1.75" y="2.35" dx="0.3" dy="0.7" layer="1" roundness="50"/>
<text x="-2.54" y="3.175" size="1.27" layer="25">&gt;NAME</text>
<text x="-2.54" y="-4.445" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-2.5" y1="1.6" x2="-2.05" y2="1.9" layer="51"/>
<rectangle x1="-2.5" y1="1.1" x2="-2.05" y2="1.4" layer="51"/>
<rectangle x1="-2.5" y1="0.6" x2="-2.05" y2="0.9" layer="51"/>
<rectangle x1="-2.5" y1="0.1" x2="-2.05" y2="0.4" layer="51"/>
<rectangle x1="-2.5" y1="-0.4" x2="-2.05" y2="-0.1" layer="51"/>
<rectangle x1="-2.5" y1="-0.9" x2="-2.05" y2="-0.6" layer="51"/>
<rectangle x1="-2.5" y1="-1.4" x2="-2.05" y2="-1.1" layer="51"/>
<rectangle x1="-2.5" y1="-1.9" x2="-2.05" y2="-1.6" layer="51"/>
<rectangle x1="-1.9" y1="-2.5" x2="-1.6" y2="-2.05" layer="51"/>
<rectangle x1="-1.4" y1="-2.5" x2="-1.1" y2="-2.05" layer="51"/>
<rectangle x1="-0.9" y1="-2.5" x2="-0.6" y2="-2.05" layer="51"/>
<rectangle x1="-0.4" y1="-2.5" x2="-0.1" y2="-2.05" layer="51"/>
<rectangle x1="0.1" y1="-2.5" x2="0.4" y2="-2.05" layer="51"/>
<rectangle x1="0.6" y1="-2.5" x2="0.9" y2="-2.05" layer="51"/>
<rectangle x1="1.1" y1="-2.5" x2="1.4" y2="-2.05" layer="51"/>
<rectangle x1="1.6" y1="-2.5" x2="1.9" y2="-2.05" layer="51"/>
<rectangle x1="2.05" y1="-1.9" x2="2.5" y2="-1.6" layer="51"/>
<rectangle x1="2.05" y1="-1.4" x2="2.5" y2="-1.1" layer="51"/>
<rectangle x1="2.05" y1="-0.9" x2="2.5" y2="-0.6" layer="51"/>
<rectangle x1="2.05" y1="-0.4" x2="2.5" y2="-0.1" layer="51"/>
<rectangle x1="2.05" y1="0.1" x2="2.5" y2="0.4" layer="51"/>
<rectangle x1="2.05" y1="0.6" x2="2.5" y2="0.9" layer="51"/>
<rectangle x1="2.05" y1="1.1" x2="2.5" y2="1.4" layer="51"/>
<rectangle x1="2.05" y1="1.6" x2="2.5" y2="1.9" layer="51"/>
<rectangle x1="1.6" y1="2.05" x2="1.9" y2="2.5" layer="51"/>
<rectangle x1="1.1" y1="2.05" x2="1.4" y2="2.5" layer="51"/>
<rectangle x1="0.6" y1="2.05" x2="0.9" y2="2.5" layer="51"/>
<rectangle x1="0.1" y1="2.05" x2="0.4" y2="2.5" layer="51"/>
<rectangle x1="-0.4" y1="2.05" x2="-0.1" y2="2.5" layer="51"/>
<rectangle x1="-0.9" y1="2.05" x2="-0.6" y2="2.5" layer="51"/>
<rectangle x1="-1.4" y1="2.05" x2="-1.1" y2="2.5" layer="51"/>
<rectangle x1="-1.9" y1="2.05" x2="-1.6" y2="2.5" layer="51"/>
<rectangle x1="-1.55" y1="-1.55" x2="1.55" y2="1.55" layer="1"/>
</package>
<package name="TQFP32-08">
<description>&lt;B&gt;Thin Plasic Quad Flat Package&lt;/B&gt; Grid 0.8 mm</description>
<wire x1="3.505" y1="3.505" x2="3.505" y2="-3.505" width="0.1524" layer="21"/>
<wire x1="3.505" y1="-3.505" x2="-3.505" y2="-3.505" width="0.1524" layer="21"/>
<wire x1="-3.505" y1="-3.505" x2="-3.505" y2="3.15" width="0.1524" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="3.505" y2="3.505" width="0.1524" layer="21"/>
<wire x1="-3.15" y1="3.505" x2="-3.505" y2="3.15" width="0.1524" layer="21"/>
<circle x="-2.7432" y="2.7432" radius="0.3592" width="0.1524" layer="21"/>
<smd name="1" x="-4.2926" y="2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="2" x="-4.2926" y="2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="3" x="-4.2926" y="1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="4" x="-4.2926" y="0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="5" x="-4.2926" y="-0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="6" x="-4.2926" y="-1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="7" x="-4.2926" y="-2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="8" x="-4.2926" y="-2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="9" x="-2.8" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="10" x="-2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="11" x="-1.2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="12" x="-0.4" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="13" x="0.4" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="14" x="1.2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="15" x="2" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="16" x="2.8" y="-4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="17" x="4.2926" y="-2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="18" x="4.2926" y="-2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="19" x="4.2926" y="-1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="20" x="4.2926" y="-0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="21" x="4.2926" y="0.4" dx="1.27" dy="0.5588" layer="1"/>
<smd name="22" x="4.2926" y="1.2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="23" x="4.2926" y="2" dx="1.27" dy="0.5588" layer="1"/>
<smd name="24" x="4.2926" y="2.8" dx="1.27" dy="0.5588" layer="1"/>
<smd name="25" x="2.8" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="26" x="2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="27" x="1.2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="28" x="0.4" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="29" x="-0.4" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="30" x="-1.2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="31" x="-2" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<smd name="32" x="-2.8" y="4.2926" dx="0.5588" dy="1.27" layer="1"/>
<text x="-2.7686" y="5.08" size="0.8128" layer="25">&gt;NAME</text>
<text x="-3.0226" y="-1.27" size="0.8128" layer="27">&gt;VALUE</text>
<rectangle x1="-4.5466" y1="2.5714" x2="-3.556" y2="3.0286" layer="51"/>
<rectangle x1="-4.5466" y1="1.7714" x2="-3.556" y2="2.2286" layer="51"/>
<rectangle x1="-4.5466" y1="0.9714" x2="-3.556" y2="1.4286" layer="51"/>
<rectangle x1="-4.5466" y1="0.1714" x2="-3.556" y2="0.6286" layer="51"/>
<rectangle x1="-4.5466" y1="-0.6286" x2="-3.556" y2="-0.1714" layer="51"/>
<rectangle x1="-4.5466" y1="-1.4286" x2="-3.556" y2="-0.9714" layer="51"/>
<rectangle x1="-4.5466" y1="-2.2286" x2="-3.556" y2="-1.7714" layer="51"/>
<rectangle x1="-4.5466" y1="-3.0286" x2="-3.556" y2="-2.5714" layer="51"/>
<rectangle x1="-3.0286" y1="-4.5466" x2="-2.5714" y2="-3.556" layer="51"/>
<rectangle x1="-2.2286" y1="-4.5466" x2="-1.7714" y2="-3.556" layer="51"/>
<rectangle x1="-1.4286" y1="-4.5466" x2="-0.9714" y2="-3.556" layer="51"/>
<rectangle x1="-0.6286" y1="-4.5466" x2="-0.1714" y2="-3.556" layer="51"/>
<rectangle x1="0.1714" y1="-4.5466" x2="0.6286" y2="-3.556" layer="51"/>
<rectangle x1="0.9714" y1="-4.5466" x2="1.4286" y2="-3.556" layer="51"/>
<rectangle x1="1.7714" y1="-4.5466" x2="2.2286" y2="-3.556" layer="51"/>
<rectangle x1="2.5714" y1="-4.5466" x2="3.0286" y2="-3.556" layer="51"/>
<rectangle x1="3.556" y1="-3.0286" x2="4.5466" y2="-2.5714" layer="51"/>
<rectangle x1="3.556" y1="-2.2286" x2="4.5466" y2="-1.7714" layer="51"/>
<rectangle x1="3.556" y1="-1.4286" x2="4.5466" y2="-0.9714" layer="51"/>
<rectangle x1="3.556" y1="-0.6286" x2="4.5466" y2="-0.1714" layer="51"/>
<rectangle x1="3.556" y1="0.1714" x2="4.5466" y2="0.6286" layer="51"/>
<rectangle x1="3.556" y1="0.9714" x2="4.5466" y2="1.4286" layer="51"/>
<rectangle x1="3.556" y1="1.7714" x2="4.5466" y2="2.2286" layer="51"/>
<rectangle x1="3.556" y1="2.5714" x2="4.5466" y2="3.0286" layer="51"/>
<rectangle x1="2.5714" y1="3.556" x2="3.0286" y2="4.5466" layer="51"/>
<rectangle x1="1.7714" y1="3.556" x2="2.2286" y2="4.5466" layer="51"/>
<rectangle x1="0.9714" y1="3.556" x2="1.4286" y2="4.5466" layer="51"/>
<rectangle x1="0.1714" y1="3.556" x2="0.6286" y2="4.5466" layer="51"/>
<rectangle x1="-0.6286" y1="3.556" x2="-0.1714" y2="4.5466" layer="51"/>
<rectangle x1="-1.4286" y1="3.556" x2="-0.9714" y2="4.5466" layer="51"/>
<rectangle x1="-2.2286" y1="3.556" x2="-1.7714" y2="4.5466" layer="51"/>
<rectangle x1="-3.0286" y1="3.556" x2="-2.5714" y2="4.5466" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGA48/88/168-TQFP/QFN32">
<wire x1="-25.4" y1="30.48" x2="25.4" y2="30.48" width="0.254" layer="94"/>
<wire x1="25.4" y1="30.48" x2="25.4" y2="-33.02" width="0.254" layer="94"/>
<wire x1="25.4" y1="-33.02" x2="-25.4" y2="-33.02" width="0.254" layer="94"/>
<wire x1="-25.4" y1="-33.02" x2="-25.4" y2="30.48" width="0.254" layer="94"/>
<text x="-25.4" y="33.02" size="1.778" layer="95" rot="MR180">&gt;NAME</text>
<text x="-25.4" y="-35.56" size="1.778" layer="96">&gt;VALUE</text>
<pin name="PB5(SCK/PCINT5)" x="30.48" y="-30.48" length="middle" rot="R180"/>
<pin name="PB7(XTAL2/TOSC2/PCINT7)" x="-30.48" y="7.62" length="middle"/>
<pin name="PB6(XTAL1/TOSC1/PCINT6)" x="-30.48" y="12.7" length="middle"/>
<pin name="GND@1" x="-30.48" y="-27.94" length="middle" direction="pwr"/>
<pin name="VCC@1" x="-30.48" y="0" length="middle" direction="pwr"/>
<pin name="AGND" x="-30.48" y="-22.86" length="middle" direction="pwr"/>
<pin name="AREF" x="-30.48" y="-10.16" length="middle" direction="pas"/>
<pin name="AVCC" x="-30.48" y="-7.62" length="middle" direction="pas"/>
<pin name="PB4(MISO/PCINT4)" x="30.48" y="-27.94" length="middle" rot="R180"/>
<pin name="PB3(MOSI/OC2A/PCINT3)" x="30.48" y="-25.4" length="middle" rot="R180"/>
<pin name="PB2(SS/OC1B/PCINT2)" x="30.48" y="-22.86" length="middle" rot="R180"/>
<pin name="PB1(OC1A/PCINT1)" x="30.48" y="-20.32" length="middle" rot="R180"/>
<pin name="PB0(ICP1/CLKO/PCINT0)" x="30.48" y="-17.78" length="middle" rot="R180"/>
<pin name="PD7(AIN1/PCINT23)" x="30.48" y="-12.7" length="middle" rot="R180"/>
<pin name="PD6(AIN0/OC0A/PCINT22)" x="30.48" y="-10.16" length="middle" rot="R180"/>
<pin name="PD5(T1/OC0B/PCINT21)" x="30.48" y="-7.62" length="middle" rot="R180"/>
<pin name="PD4(T0/XCK/PCINT20)" x="30.48" y="-5.08" length="middle" rot="R180"/>
<pin name="PD3(INT1/OC2B/PCINT19)" x="30.48" y="-2.54" length="middle" rot="R180"/>
<pin name="PD2(INT0/PCINT18)" x="30.48" y="0" length="middle" rot="R180"/>
<pin name="PD1(TXD/PCINT17)" x="30.48" y="2.54" length="middle" rot="R180"/>
<pin name="PD0(RXD/PCINT16)" x="30.48" y="5.08" length="middle" rot="R180"/>
<pin name="PC5(ADC5/SCL/PCINT13)" x="30.48" y="15.24" length="middle" rot="R180"/>
<pin name="PC4(ADC4/SDA/PCINT12)" x="30.48" y="17.78" length="middle" rot="R180"/>
<pin name="PC3(ADC3/PCINT11)" x="30.48" y="20.32" length="middle" rot="R180"/>
<pin name="PC2(ADC2/PCINT10)" x="30.48" y="22.86" length="middle" rot="R180"/>
<pin name="PC1(ADC1/PCINT9)" x="30.48" y="25.4" length="middle" rot="R180"/>
<pin name="PC0(ADC0/PCINT8)" x="30.48" y="27.94" length="middle" rot="R180"/>
<pin name="PC6(/RESET/PCINT14)" x="-30.48" y="27.94" length="middle"/>
<pin name="GND@2" x="-30.48" y="-30.48" length="middle" direction="pwr"/>
<pin name="VCC@2" x="-30.48" y="-2.54" length="middle" direction="pwr"/>
<pin name="ADC7" x="30.48" y="10.16" length="middle" direction="pas" rot="R180"/>
<pin name="ADC6" x="30.48" y="12.7" length="middle" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA48/88/168" prefix="IC">
<gates>
<gate name="1" symbol="ATMEGA48/88/168-TQFP/QFN32" x="0" y="0"/>
</gates>
<devices>
<device name="-MU" package="MLF32">
<connects>
<connect gate="1" pin="ADC6" pad="19"/>
<connect gate="1" pin="ADC7" pad="22"/>
<connect gate="1" pin="AGND" pad="21"/>
<connect gate="1" pin="AREF" pad="20"/>
<connect gate="1" pin="AVCC" pad="18"/>
<connect gate="1" pin="GND@1" pad="3"/>
<connect gate="1" pin="GND@2" pad="5"/>
<connect gate="1" pin="PB0(ICP1/CLKO/PCINT0)" pad="12"/>
<connect gate="1" pin="PB1(OC1A/PCINT1)" pad="13"/>
<connect gate="1" pin="PB2(SS/OC1B/PCINT2)" pad="14"/>
<connect gate="1" pin="PB3(MOSI/OC2A/PCINT3)" pad="15"/>
<connect gate="1" pin="PB4(MISO/PCINT4)" pad="16"/>
<connect gate="1" pin="PB5(SCK/PCINT5)" pad="17"/>
<connect gate="1" pin="PB6(XTAL1/TOSC1/PCINT6)" pad="7"/>
<connect gate="1" pin="PB7(XTAL2/TOSC2/PCINT7)" pad="8"/>
<connect gate="1" pin="PC0(ADC0/PCINT8)" pad="23"/>
<connect gate="1" pin="PC1(ADC1/PCINT9)" pad="24"/>
<connect gate="1" pin="PC2(ADC2/PCINT10)" pad="25"/>
<connect gate="1" pin="PC3(ADC3/PCINT11)" pad="26"/>
<connect gate="1" pin="PC4(ADC4/SDA/PCINT12)" pad="27"/>
<connect gate="1" pin="PC5(ADC5/SCL/PCINT13)" pad="28"/>
<connect gate="1" pin="PC6(/RESET/PCINT14)" pad="29"/>
<connect gate="1" pin="PD0(RXD/PCINT16)" pad="30"/>
<connect gate="1" pin="PD1(TXD/PCINT17)" pad="31"/>
<connect gate="1" pin="PD2(INT0/PCINT18)" pad="32"/>
<connect gate="1" pin="PD3(INT1/OC2B/PCINT19)" pad="1"/>
<connect gate="1" pin="PD4(T0/XCK/PCINT20)" pad="2"/>
<connect gate="1" pin="PD5(T1/OC0B/PCINT21)" pad="9"/>
<connect gate="1" pin="PD6(AIN0/OC0A/PCINT22)" pad="10"/>
<connect gate="1" pin="PD7(AIN1/PCINT23)" pad="11"/>
<connect gate="1" pin="VCC@1" pad="4"/>
<connect gate="1" pin="VCC@2" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="-AU" package="TQFP32-08">
<connects>
<connect gate="1" pin="ADC6" pad="19"/>
<connect gate="1" pin="ADC7" pad="22"/>
<connect gate="1" pin="AGND" pad="21"/>
<connect gate="1" pin="AREF" pad="20"/>
<connect gate="1" pin="AVCC" pad="18"/>
<connect gate="1" pin="GND@1" pad="3"/>
<connect gate="1" pin="GND@2" pad="5"/>
<connect gate="1" pin="PB0(ICP1/CLKO/PCINT0)" pad="12"/>
<connect gate="1" pin="PB1(OC1A/PCINT1)" pad="13"/>
<connect gate="1" pin="PB2(SS/OC1B/PCINT2)" pad="14"/>
<connect gate="1" pin="PB3(MOSI/OC2A/PCINT3)" pad="15"/>
<connect gate="1" pin="PB4(MISO/PCINT4)" pad="16"/>
<connect gate="1" pin="PB5(SCK/PCINT5)" pad="17"/>
<connect gate="1" pin="PB6(XTAL1/TOSC1/PCINT6)" pad="7"/>
<connect gate="1" pin="PB7(XTAL2/TOSC2/PCINT7)" pad="8"/>
<connect gate="1" pin="PC0(ADC0/PCINT8)" pad="23"/>
<connect gate="1" pin="PC1(ADC1/PCINT9)" pad="24"/>
<connect gate="1" pin="PC2(ADC2/PCINT10)" pad="25"/>
<connect gate="1" pin="PC3(ADC3/PCINT11)" pad="26"/>
<connect gate="1" pin="PC4(ADC4/SDA/PCINT12)" pad="27"/>
<connect gate="1" pin="PC5(ADC5/SCL/PCINT13)" pad="28"/>
<connect gate="1" pin="PC6(/RESET/PCINT14)" pad="29"/>
<connect gate="1" pin="PD0(RXD/PCINT16)" pad="30"/>
<connect gate="1" pin="PD1(TXD/PCINT17)" pad="31"/>
<connect gate="1" pin="PD2(INT0/PCINT18)" pad="32"/>
<connect gate="1" pin="PD3(INT1/OC2B/PCINT19)" pad="1"/>
<connect gate="1" pin="PD4(T0/XCK/PCINT20)" pad="2"/>
<connect gate="1" pin="PD5(T1/OC0B/PCINT21)" pad="9"/>
<connect gate="1" pin="PD6(AIN0/OC0A/PCINT22)" pad="10"/>
<connect gate="1" pin="PD7(AIN1/PCINT23)" pad="11"/>
<connect gate="1" pin="VCC@1" pad="4"/>
<connect gate="1" pin="VCC@2" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="#PaJa_konektory">
<description>&lt;B&gt;PaJa_konektory&lt;/B&gt; - knihovna   &amp;nbsp; &amp;nbsp; &amp;nbsp; &amp;nbsp; &amp;nbsp; &amp;nbsp; 
&lt;I&gt;(vytvoreno 1.6.2011)&lt;/I&gt;&lt;BR&gt;
Knihovna konektoru do Eagle &lt;I&gt;(od verze 5.6)&lt;/I&gt;&lt;BR&gt;
&lt;BR&gt;
Knihovna obsahuje: 91 soucastek na DPS, 92 do SCHematu&lt;BR&gt;
&lt;BR&gt;
&lt;Author&gt;Copyright (C) PaJa 2011&lt;BR&gt;
http://www.paja-trb.unas.cz&lt;BR&gt;
paja-trb@seznam.cz
&lt;/author&gt;</description>
<packages>
<package name="PSH02-04P">
<wire x1="-5.08" y1="2.54" x2="-3.81" y2="2.54" width="0.127" layer="21"/>
<wire x1="-5.08" y1="2.54" x2="-5.08" y2="-3.175" width="0.127" layer="21"/>
<wire x1="-3.81" y1="2.54" x2="-3.81" y2="1.5875" width="0.127" layer="21"/>
<wire x1="-3.81" y1="2.54" x2="3.81" y2="2.54" width="0.127" layer="21"/>
<wire x1="3.81" y1="2.54" x2="5.08" y2="2.54" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-3.175" x2="5.08" y2="-3.175" width="0.127" layer="21"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-3.175" width="0.127" layer="21"/>
<wire x1="3.81" y1="1.5875" x2="3.81" y2="2.54" width="0.127" layer="21"/>
<wire x1="-3.81" y1="1.5875" x2="3.81" y2="1.5875" width="0.127" layer="21"/>
<circle x="-3.81" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="-1.27" y="0" radius="0.5723" width="0.127" layer="102"/>
<circle x="1.27" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="3.81" y="0" radius="0.5723" width="0.127" layer="102"/>
<pad name="1" x="-3.81" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<text x="-4.9213" y="2.0638" size="0.254" layer="100">PaJa</text>
<text x="-4.9212" y="-3.0163" size="1.4224" layer="25">&gt;Name</text>
<text x="-4.9212" y="-4.9212" size="1.4224" layer="27">&gt;Value</text>
<rectangle x1="-4.1275" y1="-0.3175" x2="-3.4925" y2="0.3175" layer="51"/>
<rectangle x1="-1.5875" y1="-0.3175" x2="-0.9525" y2="0.3175" layer="51"/>
<rectangle x1="0.9525" y1="-0.3175" x2="1.5875" y2="0.3175" layer="51"/>
<rectangle x1="3.4925" y1="-0.3175" x2="4.1275" y2="0.3175" layer="51"/>
</package>
<package name="PSH02-04W">
<wire x1="-5.08" y1="5.08" x2="-3.81" y2="5.08" width="0.127" layer="21"/>
<wire x1="-5.08" y1="5.08" x2="-5.08" y2="1.905" width="0.127" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-4.445" y2="1.905" width="0.127" layer="21"/>
<wire x1="-3.175" y1="1.905" x2="-1.905" y2="1.905" width="0.127" layer="21"/>
<wire x1="-3.81" y1="5.08" x2="-3.81" y2="13.0175" width="0.127" layer="21"/>
<wire x1="-4.445" y1="1.905" x2="-4.445" y2="2.54" width="0.127" layer="21"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.127" layer="21"/>
<wire x1="-3.175" y1="2.54" x2="-3.175" y2="1.905" width="0.127" layer="21"/>
<wire x1="-1.905" y1="1.905" x2="-1.905" y2="2.54" width="0.127" layer="21"/>
<wire x1="-1.905" y1="2.54" x2="-0.635" y2="2.54" width="0.127" layer="21"/>
<wire x1="-0.635" y1="2.54" x2="-0.635" y2="1.905" width="0.127" layer="21"/>
<wire x1="-3.81" y1="5.3975" x2="-3.81" y2="12.7" width="0.6096" layer="51"/>
<wire x1="-1.27" y1="12.7" x2="-1.27" y2="5.3975" width="0.6096" layer="51"/>
<wire x1="-1.27" y1="0" x2="-1.27" y2="2.2225" width="0.6096" layer="51"/>
<wire x1="-3.81" y1="2.2225" x2="-3.81" y2="0" width="0.6096" layer="51"/>
<wire x1="-3.81" y1="5.08" x2="3.81" y2="5.08" width="0.127" layer="21"/>
<wire x1="3.81" y1="5.08" x2="5.08" y2="5.08" width="0.127" layer="21"/>
<wire x1="-0.635" y1="1.905" x2="0.635" y2="1.905" width="0.127" layer="21"/>
<wire x1="1.905" y1="1.905" x2="3.175" y2="1.905" width="0.127" layer="21"/>
<wire x1="4.445" y1="1.905" x2="5.08" y2="1.905" width="0.127" layer="21"/>
<wire x1="5.08" y1="5.08" x2="5.08" y2="1.905" width="0.127" layer="21"/>
<wire x1="-3.81" y1="13.0175" x2="3.81" y2="13.0175" width="0.127" layer="21"/>
<wire x1="3.81" y1="13.0175" x2="3.81" y2="5.08" width="0.127" layer="21"/>
<wire x1="0.635" y1="1.905" x2="0.635" y2="2.54" width="0.127" layer="21"/>
<wire x1="0.635" y1="2.54" x2="1.905" y2="2.54" width="0.127" layer="21"/>
<wire x1="1.905" y1="2.54" x2="1.905" y2="1.905" width="0.127" layer="21"/>
<wire x1="3.175" y1="1.905" x2="3.175" y2="2.54" width="0.127" layer="21"/>
<wire x1="3.175" y1="2.54" x2="4.445" y2="2.54" width="0.127" layer="21"/>
<wire x1="4.445" y1="2.54" x2="4.445" y2="1.905" width="0.127" layer="21"/>
<wire x1="1.27" y1="5.3975" x2="1.27" y2="12.7" width="0.6096" layer="51"/>
<wire x1="3.81" y1="12.7" x2="3.81" y2="5.3975" width="0.6096" layer="51"/>
<wire x1="3.81" y1="0" x2="3.81" y2="2.2225" width="0.6096" layer="51"/>
<wire x1="1.27" y1="2.2225" x2="1.27" y2="0" width="0.6096" layer="51"/>
<circle x="-3.81" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="-1.27" y="0" radius="0.5723" width="0.127" layer="102"/>
<circle x="1.27" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="3.81" y="0" radius="0.5723" width="0.127" layer="102"/>
<pad name="1" x="-3.81" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="1.016" diameter="1.4224" shape="long" rot="R90"/>
<text x="-3.0163" y="2.0638" size="0.254" layer="100">PaJa</text>
<text x="-4.445" y="3.175" size="1.4224" layer="25">&gt;Name</text>
<text x="-1.905" y="5.3975" size="1.4224" layer="27" rot="R90">&gt;Value</text>
<rectangle x1="-1.5875" y1="0" x2="-0.9525" y2="2.54" layer="51"/>
<rectangle x1="-4.1275" y1="0" x2="-3.4925" y2="2.54" layer="51"/>
<rectangle x1="-4.1275" y1="5.08" x2="-3.4925" y2="12.7" layer="51"/>
<rectangle x1="-1.5875" y1="5.08" x2="-0.9525" y2="12.7" layer="51"/>
<rectangle x1="3.4925" y1="0" x2="4.1275" y2="2.54" layer="51"/>
<rectangle x1="0.9525" y1="0" x2="1.5875" y2="2.54" layer="51"/>
<rectangle x1="0.9525" y1="5.08" x2="1.5875" y2="12.7" layer="51"/>
<rectangle x1="3.4925" y1="5.08" x2="4.1275" y2="12.7" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="S1G4">
<wire x1="-4.445" y1="1.27" x2="-4.445" y2="5.715" width="0.4064" layer="94"/>
<wire x1="2.54" y1="3.81" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="0" y1="3.81" x2="0" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="3.81" x2="-2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="6.985" y1="5.715" x2="-4.445" y2="5.715" width="0.4064" layer="94"/>
<wire x1="-4.445" y1="1.27" x2="6.985" y2="1.27" width="0.4064" layer="94"/>
<wire x1="6.985" y1="5.715" x2="6.985" y2="1.27" width="0.4064" layer="94"/>
<wire x1="5.08" y1="3.81" x2="5.08" y2="2.54" width="0.6096" layer="94"/>
<text x="9.3662" y="0.1587" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<text x="-5.08" y="0.4762" size="1.778" layer="95" rot="R90">&gt;Part</text>
<text x="6.6675" y="1.5875" size="0.254" layer="100" rot="R90">PaJa</text>
<pin name="1" x="-2.54" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R90"/>
<pin name="2" x="0" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R90"/>
<pin name="3" x="2.54" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R90"/>
<pin name="4" x="5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PSH02-04" prefix="K" uservalue="yes">
<description>&lt;B&gt;Konektory se zamkem&lt;/B&gt; - vidlice - 4pin</description>
<gates>
<gate name="KON" symbol="S1G4" x="0" y="-2.54" swaplevel="2"/>
</gates>
<devices>
<device name="P" package="PSH02-04P">
<connects>
<connect gate="KON" pin="1" pad="1"/>
<connect gate="KON" pin="2" pad="2"/>
<connect gate="KON" pin="3" pad="3"/>
<connect gate="KON" pin="4" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="W" package="PSH02-04W">
<connects>
<connect gate="KON" pin="1" pad="1"/>
<connect gate="KON" pin="2" pad="2"/>
<connect gate="KON" pin="3" pad="3"/>
<connect gate="KON" pin="4" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="IC1" library="atmega8" deviceset="ATMEGA48/88/168" device="-AU"/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="K1" library="#PaJa_konektory" deviceset="PSH02-04" device="W"/>
<part name="K2" library="#PaJa_konektory" deviceset="PSH02-04" device="W"/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="P+2" library="supply1" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" deviceset="VCC" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="IC1" gate="1" x="93.98" y="66.04"/>
<instance part="P+1" gate="VCC" x="53.34" y="66.04" rot="R90"/>
<instance part="GND1" gate="1" x="53.34" y="38.1" rot="R270"/>
<instance part="K1" gate="KON" x="167.64" y="91.44" rot="R270"/>
<instance part="K2" gate="KON" x="167.64" y="68.58" rot="R270"/>
<instance part="GND2" gate="1" x="162.56" y="78.74"/>
<instance part="GND3" gate="1" x="162.56" y="55.88"/>
<instance part="P+2" gate="VCC" x="157.48" y="55.88" rot="R180"/>
<instance part="P+3" gate="VCC" x="157.48" y="78.74" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="IC1" gate="1" pin="VCC@1"/>
<wire x1="63.5" y1="66.04" x2="55.88" y2="66.04" width="0.1524" layer="91"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="K1" gate="KON" pin="3"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
<wire x1="165.1" y1="88.9" x2="157.48" y2="88.9" width="0.1524" layer="91"/>
<wire x1="157.48" y1="88.9" x2="157.48" y2="81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="K2" gate="KON" pin="3"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
<wire x1="165.1" y1="66.04" x2="157.48" y2="66.04" width="0.1524" layer="91"/>
<wire x1="157.48" y1="66.04" x2="157.48" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="IC1" gate="1" pin="GND@1"/>
<wire x1="63.5" y1="38.1" x2="55.88" y2="38.1" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
</segment>
<segment>
<pinref part="K1" gate="KON" pin="4"/>
<wire x1="165.1" y1="86.36" x2="162.56" y2="86.36" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="162.56" y1="86.36" x2="162.56" y2="81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="K2" gate="KON" pin="4"/>
<wire x1="165.1" y1="63.5" x2="162.56" y2="63.5" width="0.1524" layer="91"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="162.56" y1="63.5" x2="162.56" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="IC1" gate="1" pin="PC0(ADC0/PCINT8)"/>
<pinref part="K1" gate="KON" pin="1"/>
<wire x1="124.46" y1="93.98" x2="165.1" y2="93.98" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="K1" gate="KON" pin="2"/>
<pinref part="IC1" gate="1" pin="PC1(ADC1/PCINT9)"/>
<wire x1="165.1" y1="91.44" x2="124.46" y2="91.44" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="K2" gate="KON" pin="1"/>
<pinref part="IC1" gate="1" pin="PD0(RXD/PCINT16)"/>
<wire x1="165.1" y1="71.12" x2="124.46" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="K2" gate="KON" pin="2"/>
<pinref part="IC1" gate="1" pin="PD1(TXD/PCINT17)"/>
<wire x1="165.1" y1="68.58" x2="124.46" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
