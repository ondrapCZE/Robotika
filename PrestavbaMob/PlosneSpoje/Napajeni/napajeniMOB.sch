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
<layer number="23" name="tOrigins" color="13" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="3" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="11" fill="1" visible="no" active="no"/>
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
<layer number="45" name="Holes" color="10" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="14" fill="1" visible="no" active="no"/>
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
<layer number="103" name="Popisy" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Zapojeni" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="no" active="no"/>
<layer number="200" name="200bmp" color="7" fill="1" visible="no" active="no"/>
<layer number="250" name="Descript" color="7" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="7" fill="1" visible="no" active="no"/>
<layer number="254" name="OrgLBR" color="7" fill="1" visible="no" active="no"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="#PaJa_30">
<description>&lt;B&gt;PaJa 30&lt;/B&gt; - knihovna   &amp;nbsp; &amp;nbsp; &amp;nbsp; &amp;nbsp; &amp;nbsp; &amp;nbsp; 
&lt;I&gt;(vytvoreno 1.6.2011)&lt;/I&gt;&lt;BR&gt;
Univerzální knihovna soucastek do Eagle &lt;I&gt;(od verze 5.6)&lt;/I&gt;&lt;BR&gt;
&lt;BR&gt;
Knihovna obsahuje: 196 soucastek na DPS, 298 do SCHematu&lt;BR&gt;
&lt;BR&gt;
&lt;Author&gt;Copyright (C) PaJa 2001-2011&lt;BR&gt;
http://www.paja-trb.unas.cz&lt;BR&gt;
paja-trb@seznam.cz
&lt;/author&gt;</description>
<packages>
<package name="TO-92">
<wire x1="-1.5875" y1="1.905" x2="-1.5875" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-1.1113" y1="2.2225" x2="1.1113" y2="2.2225" width="0.127" layer="51" curve="-53.132165"/>
<wire x1="2.2225" y1="1.1113" x2="2.2225" y2="-1.1113" width="0.127" layer="51" curve="-53.132165"/>
<wire x1="1.1113" y1="-2.2225" x2="-1.1113" y2="-2.2225" width="0.127" layer="51" curve="-53.132165"/>
<wire x1="-1.5875" y1="1.905" x2="-1.1113" y2="2.2225" width="0.127" layer="21" curve="-13.162519"/>
<wire x1="-1.5875" y1="-1.905" x2="-1.1113" y2="-2.2225" width="0.127" layer="21" curve="13.162519"/>
<wire x1="1.1113" y1="-2.2225" x2="2.2225" y2="-1.1113" width="0.127" layer="21" curve="36.867835"/>
<wire x1="2.2225" y1="1.1113" x2="1.1113" y2="2.2225" width="0.127" layer="21" curve="36.867835"/>
<circle x="2.544" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="0" y="2.544" radius="0.477" width="0.127" layer="102"/>
<circle x="0" y="-2.544" radius="0.477" width="0.127" layer="102"/>
<pad name="3" x="0" y="-2.54" drill="0.8128" diameter="1.9304" shape="octagon"/>
<pad name="2" x="2.54" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<pad name="1" x="0" y="2.54" drill="0.8128" diameter="1.9304" shape="octagon"/>
<text x="0.1017" y="-1.2159" size="1.27" layer="25" font="vector" rot="R90">&gt;Name</text>
<text x="-1.6917" y="-2.8625" size="1.27" layer="27" font="vector" rot="R90">&gt;Value</text>
<text x="1.5895" y="-0.477" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
</package>
<package name="DO35">
<description>&lt;B&gt;Dioda&lt;/B&gt; - roztec nozek 7,5 mm</description>
<wire x1="-2.2235" y1="-0.889" x2="2.2235" y2="-0.889" width="0.127" layer="21"/>
<wire x1="2.2235" y1="-0.889" x2="2.2235" y2="0" width="0.127" layer="21"/>
<wire x1="2.2235" y1="0.889" x2="-2.2235" y2="0.889" width="0.127" layer="21"/>
<wire x1="2.2235" y1="0" x2="2.572" y2="0" width="0.127" layer="21"/>
<wire x1="2.2235" y1="0" x2="2.2235" y2="0.889" width="0.127" layer="21"/>
<wire x1="-2.572" y1="0" x2="-2.2235" y2="0" width="0.127" layer="21"/>
<wire x1="-2.2235" y1="0" x2="-2.2235" y2="-0.889" width="0.127" layer="21"/>
<wire x1="-2.2235" y1="0.889" x2="-2.2235" y2="0" width="0.127" layer="21"/>
<wire x1="-2.612" y1="0" x2="-3.259" y2="0" width="0.127" layer="51"/>
<wire x1="3.259" y1="0" x2="2.612" y2="0" width="0.127" layer="51"/>
<circle x="-3.816" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="3.816" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="K" x="3.81" y="0" drill="0.8128" diameter="1.9304" shape="square"/>
<pad name="A" x="-3.81" y="0" drill="0.8128" diameter="1.9304"/>
<text x="-2.0675" y="-0.636" size="1.27" layer="25" font="vector">&gt;Name</text>
<text x="-2.069" y="-2.385" size="1.27" layer="27" font="vector">&gt;Value</text>
<text x="-2.617" y="-0.9985" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="1.0805" y1="-0.889" x2="1.5885" y2="0.889" layer="21"/>
</package>
<package name="DO41">
<description>&lt;B&gt;Dioda&lt;/B&gt; - roztec nozek 10 mm</description>
<wire x1="-3.0163" y1="1.5875" x2="3.0163" y2="1.5875" width="0.127" layer="21"/>
<wire x1="3.0163" y1="1.5875" x2="3.0163" y2="-1.5875" width="0.127" layer="21"/>
<wire x1="3.0163" y1="-1.5875" x2="-3.0163" y2="-1.5875" width="0.127" layer="21"/>
<wire x1="-3.0163" y1="-1.5875" x2="-3.0163" y2="1.5875" width="0.127" layer="21"/>
<circle x="-5.08" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="5.08" y="0" radius="0.5724" width="0.127" layer="102"/>
<pad name="K" x="5.08" y="0" drill="1.016" diameter="2.1844" shape="square"/>
<pad name="A" x="-5.08" y="0" drill="1.016" diameter="2.1844"/>
<text x="-2.8655" y="0.14" size="1.27" layer="25" font="vector">&gt;NAME</text>
<text x="-2.8655" y="-1.315" size="1.27" layer="27" font="vector">&gt;VALUE</text>
<text x="-3.169" y="0.4765" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="1.842" y1="-1.524" x2="2.604" y2="1.524" layer="21"/>
<rectangle x1="3.0163" y1="-0.3175" x2="3.81" y2="0.3175" layer="21"/>
<rectangle x1="-3.81" y1="-0.3175" x2="-3.0163" y2="0.3175" layer="21"/>
<rectangle x1="-4.6038" y1="-0.3175" x2="-3.81" y2="0.3175" layer="51"/>
<rectangle x1="3.81" y1="-0.3175" x2="4.6038" y2="0.3175" layer="51"/>
</package>
<package name="SOD-80">
<wire x1="-1.5241" y1="0.635" x2="1.2001" y2="0.635" width="0.127" layer="21"/>
<wire x1="1.2001" y1="0.635" x2="1.2001" y2="-0.635" width="0.127" layer="21"/>
<wire x1="1.2001" y1="-0.635" x2="-1.5241" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-1.5241" y1="-0.635" x2="-1.5241" y2="0.635" width="0.127" layer="21"/>
<wire x1="-0.7938" y1="0" x2="0.1588" y2="0.4763" width="0.127" layer="21"/>
<wire x1="0.1588" y1="-0.4763" x2="-0.7938" y2="0" width="0.127" layer="21"/>
<wire x1="0.1588" y1="0.4763" x2="0.1588" y2="-0.4763" width="0.127" layer="21"/>
<smd name="A" x="1.905" y="0" dx="1.397" dy="1.7018" layer="1"/>
<smd name="K" x="-2.2225" y="0" dx="1.397" dy="1.7018" layer="1"/>
<text x="0.7145" y="-0.3968" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<text x="-2.3813" y="-2.0637" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="-2.3812" y="1.1114" size="1.016" layer="25" font="vector">&gt;Name</text>
<rectangle x1="-1.0349" y1="-0.635" x2="-0.6793" y2="0.635" layer="21"/>
<rectangle x1="-1.905" y1="-0.7938" x2="-1.4288" y2="0.7938" layer="51"/>
<rectangle x1="1.1113" y1="-0.7938" x2="1.5875" y2="0.7938" layer="51"/>
</package>
<package name="SOT-23">
<description>&lt;b&gt;SMD tranzistor&lt;/b&gt;</description>
<wire x1="1.4288" y1="-0.3175" x2="-1.4288" y2="-0.3175" width="0.127" layer="21"/>
<wire x1="-1.4288" y1="-0.3175" x2="-1.4288" y2="0.4763" width="0.127" layer="21"/>
<wire x1="-1.4288" y1="0.4763" x2="1.4288" y2="0.4763" width="0.127" layer="21"/>
<wire x1="1.4288" y1="0.4763" x2="1.4288" y2="-0.3175" width="0.127" layer="21"/>
<smd name="1" x="-0.9525" y="-0.9525" dx="0.7874" dy="0.889" layer="1"/>
<smd name="2" x="0.9525" y="-0.9525" dx="0.7874" dy="0.889" layer="1"/>
<smd name="3" x="0" y="1.27" dx="0.7874" dy="0.889" layer="1"/>
<text x="-1.2701" y="-0.0001" size="0.254" layer="100" font="vector">PaJa</text>
<text x="-1.27" y="-2.5401" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="0.6351" y="0.7938" size="1.016" layer="25" font="vector">&gt;Name</text>
<rectangle x1="-0.1588" y1="0.4763" x2="0.1588" y2="1.1113" layer="51"/>
<rectangle x1="-1.1113" y1="-0.9525" x2="-0.7938" y2="-0.3175" layer="51"/>
<rectangle x1="0.7938" y1="-0.9525" x2="1.1113" y2="-0.3175" layer="51"/>
</package>
<package name="DO201">
<description>&lt;B&gt;Dioda&lt;/B&gt; - roztec nozek 12,7 mm</description>
<wire x1="-4.7625" y1="-2.8575" x2="4.7625" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="-4.7625" y1="-2.8575" x2="-4.7625" y2="2.8575" width="0.127" layer="21"/>
<wire x1="-4.7625" y1="2.8575" x2="4.7625" y2="2.8575" width="0.127" layer="21"/>
<wire x1="4.7625" y1="2.8575" x2="4.7625" y2="-2.8575" width="0.127" layer="21"/>
<circle x="-6.35" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="6.35" y="0" radius="0.5724" width="0.127" layer="102"/>
<pad name="K" x="6.35" y="0" drill="1.016" diameter="2.8" shape="square"/>
<pad name="A" x="-6.35" y="0" drill="1.016" diameter="2.8"/>
<text x="4.451" y="-0.476" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<text x="-4.2862" y="0.635" size="1.6764" layer="25" font="vector">&gt;Name</text>
<text x="-4.2863" y="-2.2225" size="1.6764" layer="27" font="vector">&gt;Value</text>
<rectangle x1="2.54" y1="-2.8575" x2="3.81" y2="2.8575" layer="21"/>
<rectangle x1="-5.8738" y1="-0.3175" x2="-4.7625" y2="0.3175" layer="51"/>
<rectangle x1="4.7626" y1="-0.3175" x2="5.8738" y2="0.3175" layer="51"/>
</package>
<package name="R-5">
<description>&lt;B&gt;Odpor&lt;/B&gt; - vel. 0204 - 0,4W - miniaturni</description>
<wire x1="-1.778" y1="0.635" x2="-1.524" y2="0.889" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="-1.778" y1="-0.635" x2="-1.524" y2="-0.889" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="1.524" y1="-0.889" x2="1.778" y2="-0.635" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="1.524" y1="0.889" x2="1.778" y2="0.6388" width="0.127" layer="21" curve="-89.149199"/>
<wire x1="1.778" y1="0.6388" x2="1.778" y2="0.635" width="0.127" layer="21" curve="-0.857165"/>
<wire x1="-1.524" y1="0.889" x2="-1.27" y2="0.889" width="0.127" layer="21"/>
<wire x1="-1.143" y1="0.762" x2="-1.27" y2="0.889" width="0.127" layer="21"/>
<wire x1="-1.524" y1="-0.889" x2="-1.27" y2="-0.889" width="0.127" layer="21"/>
<wire x1="-1.143" y1="-0.762" x2="-1.27" y2="-0.889" width="0.127" layer="21"/>
<wire x1="1.143" y1="0.762" x2="1.27" y2="0.889" width="0.127" layer="21"/>
<wire x1="1.143" y1="0.762" x2="-1.143" y2="0.762" width="0.127" layer="21"/>
<wire x1="1.143" y1="-0.762" x2="1.27" y2="-0.889" width="0.127" layer="21"/>
<wire x1="1.143" y1="-0.762" x2="-1.143" y2="-0.762" width="0.127" layer="21"/>
<wire x1="1.524" y1="0.889" x2="1.27" y2="0.889" width="0.127" layer="21"/>
<wire x1="1.524" y1="-0.889" x2="1.27" y2="-0.889" width="0.127" layer="21"/>
<wire x1="1.778" y1="0.6388" x2="1.778" y2="-0.6332" width="0.127" layer="51"/>
<wire x1="-1.7787" y1="0.6274" x2="-1.7787" y2="-0.6446" width="0.127" layer="51"/>
<circle x="-2.54" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="2.54" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-2.54" y="0" drill="0.8128" diameter="1.778" shape="octagon"/>
<pad name="2" x="2.54" y="0" drill="0.8128" diameter="1.778" shape="octagon"/>
<text x="-1.59" y="-0.477" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="-2.544" y="-1.908" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="-0.4797" y="0.8527" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="-2.1022" y1="-0.306" x2="-1.8124" y2="0.3068" layer="51"/>
<rectangle x1="1.8124" y1="-0.3068" x2="2.1022" y2="0.306" layer="51"/>
</package>
<package name="R-10">
<description>&lt;B&gt;Odpor&lt;/B&gt; - vel. 0207 - 0,6W - vetsi roztec</description>
<wire x1="-2.572" y1="1.016" x2="-2.699" y2="1.143" width="0.127" layer="21"/>
<wire x1="-2.572" y1="-1.016" x2="-2.699" y2="-1.143" width="0.127" layer="21"/>
<wire x1="2.572" y1="1.016" x2="2.699" y2="1.143" width="0.127" layer="21"/>
<wire x1="2.572" y1="1.016" x2="-2.572" y2="1.016" width="0.127" layer="21"/>
<wire x1="2.572" y1="-1.016" x2="2.699" y2="-1.143" width="0.127" layer="21"/>
<wire x1="2.572" y1="-1.016" x2="-2.572" y2="-1.016" width="0.127" layer="21"/>
<wire x1="3.08" y1="1.139" x2="2.699" y2="1.139" width="0.127" layer="21"/>
<wire x1="3.08" y1="-1.147" x2="2.699" y2="-1.147" width="0.127" layer="21"/>
<wire x1="-3.334" y1="0.893" x2="-3.08" y2="1.147" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="-3.334" y1="-0.885" x2="-3.08" y2="-1.139" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="-3.08" y1="-1.139" x2="-2.699" y2="-1.139" width="0.127" layer="21"/>
<wire x1="-3.08" y1="1.147" x2="-2.699" y2="1.147" width="0.127" layer="21"/>
<wire x1="-3.3321" y1="0.8823" x2="-3.3321" y2="-0.8667" width="0.127" layer="21"/>
<wire x1="3.08" y1="-1.147" x2="3.334" y2="-0.893" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="3.08" y1="1.139" x2="3.334" y2="0.885" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="3.3321" y1="-0.8823" x2="3.3321" y2="0.8667" width="0.127" layer="21"/>
<circle x="-5.08" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="5.08" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-5.08" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<pad name="2" x="5.08" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<text x="-3.1152" y="-0.6276" size="1.27" layer="25" font="vector">&gt;Name</text>
<text x="-0.3178" y="-0.6358" size="1.27" layer="27" font="vector">&gt;Value</text>
<text x="2.3342" y="-0.9351" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="-4.6038" y1="-0.3175" x2="-3.9688" y2="0.3175" layer="51"/>
<rectangle x1="3.9688" y1="-0.3175" x2="4.6038" y2="0.3175" layer="51"/>
<rectangle x1="-3.9688" y1="-0.3175" x2="-3.3338" y2="0.3175" layer="21"/>
<rectangle x1="3.3338" y1="-0.3175" x2="3.9688" y2="0.3175" layer="21"/>
</package>
<package name="R-12,7">
<description>&lt;B&gt;Odpor&lt;/B&gt; - roztec nozek 12,7mm</description>
<wire x1="3.7648" y1="1.2546" x2="3.8918" y2="1.3816" width="0.127" layer="21"/>
<wire x1="3.7648" y1="-1.2546" x2="3.8918" y2="-1.3816" width="0.127" layer="21"/>
<wire x1="4.2728" y1="1.3776" x2="3.8918" y2="1.3776" width="0.127" layer="21"/>
<wire x1="4.2728" y1="-1.3856" x2="3.8918" y2="-1.3856" width="0.127" layer="21"/>
<wire x1="4.2728" y1="-1.3856" x2="4.5268" y2="-1.1316" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="4.2728" y1="1.3776" x2="4.5268" y2="1.1236" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="4.5249" y1="-1.1209" x2="4.5249" y2="1.1053" width="0.127" layer="21"/>
<wire x1="-3.7649" y1="1.2547" x2="-3.8919" y2="1.3817" width="0.127" layer="21"/>
<wire x1="-3.7649" y1="-1.2546" x2="-3.8919" y2="-1.3816" width="0.127" layer="21"/>
<wire x1="3.7648" y1="1.2546" x2="-3.7649" y2="1.2547" width="0.127" layer="21"/>
<wire x1="3.7648" y1="-1.2546" x2="-3.7649" y2="-1.2546" width="0.127" layer="21"/>
<wire x1="-4.5269" y1="1.1316" x2="-4.2729" y2="1.3856" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="-4.5269" y1="-1.1236" x2="-4.2729" y2="-1.3776" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="-4.2729" y1="-1.3776" x2="-3.8919" y2="-1.3776" width="0.127" layer="21"/>
<wire x1="-4.2729" y1="1.3856" x2="-3.8919" y2="1.3856" width="0.127" layer="21"/>
<wire x1="-4.525" y1="1.1209" x2="-4.525" y2="-1.1054" width="0.127" layer="21"/>
<circle x="-6.35" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="6.35" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-6.35" y="0" drill="0.8128" diameter="2.1844" shape="octagon"/>
<pad name="2" x="6.35" y="0" drill="0.8128" diameter="2.1844" shape="octagon"/>
<text x="-0.4813" y="-0.7958" size="1.4224" layer="27" font="vector">&gt;Value</text>
<text x="-4.2905" y="-0.7144" size="1.4224" layer="25" font="vector">&gt;Name</text>
<text x="3.5712" y="-1.1046" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="-5.08" y1="-0.3175" x2="-4.445" y2="0.3175" layer="21"/>
<rectangle x1="4.6038" y1="-0.3175" x2="5.08" y2="0.3175" layer="21"/>
<rectangle x1="4.445" y1="-0.3175" x2="5.08" y2="0.3175" layer="21"/>
<rectangle x1="-5.8738" y1="-0.3175" x2="-5.08" y2="0.3175" layer="51"/>
<rectangle x1="5.08" y1="-0.3175" x2="5.8738" y2="0.3175" layer="51"/>
</package>
<package name="R-7,5">
<description>&lt;B&gt;Odpor&lt;/B&gt; - vel. 0207 - 0,6W</description>
<wire x1="-3.175" y1="0.893" x2="-2.921" y2="1.147" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="-3.175" y1="-0.885" x2="-2.921" y2="-1.139" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="2.413" y1="-1.012" x2="2.54" y2="-1.139" width="0.127" layer="21"/>
<wire x1="2.413" y1="1.02" x2="2.54" y2="1.147" width="0.127" layer="21"/>
<wire x1="-2.413" y1="-1.012" x2="-2.54" y2="-1.139" width="0.127" layer="21"/>
<wire x1="-2.413" y1="-1.012" x2="2.413" y2="-1.012" width="0.127" layer="21"/>
<wire x1="-2.413" y1="1.02" x2="-2.54" y2="1.147" width="0.127" layer="21"/>
<wire x1="-2.413" y1="1.02" x2="2.413" y2="1.02" width="0.127" layer="21"/>
<wire x1="-2.921" y1="-1.139" x2="-2.54" y2="-1.139" width="0.127" layer="21"/>
<wire x1="-2.921" y1="1.147" x2="-2.54" y2="1.147" width="0.127" layer="21"/>
<wire x1="-3.1731" y1="0.8823" x2="-3.1731" y2="-0.8667" width="0.127" layer="51"/>
<wire x1="2.921" y1="-1.147" x2="3.175" y2="-0.893" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="2.921" y1="1.139" x2="3.175" y2="0.885" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="2.921" y1="1.139" x2="2.54" y2="1.139" width="0.127" layer="21"/>
<wire x1="2.921" y1="-1.147" x2="2.54" y2="-1.147" width="0.127" layer="21"/>
<wire x1="3.1731" y1="-0.8823" x2="3.1731" y2="0.8667" width="0.127" layer="51"/>
<circle x="-3.81" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="3.81" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-3.81" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<pad name="2" x="3.81" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<text x="-0.3178" y="-0.477" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="-2.7033" y="-0.477" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="2.1354" y="-0.8658" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="-3.4323" y1="-0.3053" x2="-3.1758" y2="0.3061" layer="51"/>
<rectangle x1="3.1759" y1="-0.3061" x2="3.4324" y2="0.3053" layer="51"/>
</package>
<package name="1206">
<description>&lt;B&gt;SMD&lt;/B&gt; - velikost 1206</description>
<wire x1="-1.0541" y1="0.7938" x2="-0.7938" y2="0.7938" width="0.127" layer="51"/>
<wire x1="-0.7938" y1="0.7938" x2="0.7938" y2="0.7938" width="0.127" layer="21"/>
<wire x1="0.7938" y1="0.7938" x2="1.0541" y2="0.7938" width="0.127" layer="51"/>
<wire x1="-1.0541" y1="-0.7938" x2="-0.7938" y2="-0.7938" width="0.127" layer="51"/>
<wire x1="-0.7938" y1="-0.7938" x2="0.7938" y2="-0.7938" width="0.127" layer="21"/>
<wire x1="0.7938" y1="-0.7938" x2="1.0541" y2="-0.7938" width="0.127" layer="51"/>
<wire x1="1.0541" y1="0.7938" x2="1.0541" y2="-0.7938" width="0.127" layer="51"/>
<wire x1="-1.0541" y1="0.7938" x2="-1.0541" y2="-0.7938" width="0.127" layer="51"/>
<smd name="1" x="-1.5875" y="0" dx="1.143" dy="1.7018" layer="1"/>
<smd name="2" x="1.5875" y="0" dx="1.143" dy="1.7018" layer="1"/>
<text x="-0.3175" y="-1.1906" size="0.254" layer="100" font="vector">PaJa</text>
<text x="-0.7938" y="-0.4763" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="-0.7938" y="0.9525" size="1.016" layer="27" font="vector">&gt;Value</text>
<rectangle x1="-1.4541" y1="-0.7874" x2="-0.9461" y2="0.7874" layer="51"/>
<rectangle x1="0.9461" y1="-0.7874" x2="1.4541" y2="0.7874" layer="51"/>
</package>
<package name="R-_2W">
<description>&lt;B&gt;Odpor&lt;/B&gt; - 2W - vel. 0414</description>
<wire x1="4.3998" y1="1.8896" x2="4.5268" y2="2.0166" width="0.127" layer="21"/>
<wire x1="4.3998" y1="-1.8896" x2="4.5268" y2="-2.0166" width="0.127" layer="21"/>
<wire x1="4.9078" y1="2.0126" x2="4.5268" y2="2.0126" width="0.127" layer="21"/>
<wire x1="4.9078" y1="-2.0206" x2="4.5268" y2="-2.0206" width="0.127" layer="21"/>
<wire x1="4.9078" y1="-2.0206" x2="5.1618" y2="-1.7666" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="4.9078" y1="2.0126" x2="5.1618" y2="1.7586" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="-4.3999" y1="1.8897" x2="-4.5269" y2="2.0167" width="0.127" layer="21"/>
<wire x1="-4.3999" y1="-1.8896" x2="-4.5269" y2="-2.0166" width="0.127" layer="21"/>
<wire x1="4.3998" y1="1.8896" x2="-4.3999" y2="1.8897" width="0.127" layer="21"/>
<wire x1="4.3998" y1="-1.8896" x2="-4.3999" y2="-1.8896" width="0.127" layer="21"/>
<wire x1="-5.1619" y1="1.7666" x2="-4.9079" y2="2.0206" width="0.127" layer="21" curve="-90" cap="flat"/>
<wire x1="-5.1619" y1="-1.7586" x2="-4.9079" y2="-2.0126" width="0.127" layer="21" curve="90" cap="flat"/>
<wire x1="-4.9079" y1="-2.0126" x2="-4.5269" y2="-2.0126" width="0.127" layer="21"/>
<wire x1="-4.9079" y1="2.0206" x2="-4.5269" y2="2.0206" width="0.127" layer="21"/>
<wire x1="-5.16" y1="1.7559" x2="-5.16" y2="0.9584" width="0.127" layer="21"/>
<wire x1="-5.16" y1="-0.9429" x2="-5.16" y2="-1.7404" width="0.127" layer="21"/>
<wire x1="5.1588" y1="-0.943" x2="5.1588" y2="-1.7405" width="0.127" layer="21"/>
<wire x1="5.1588" y1="1.7559" x2="5.1588" y2="0.9584" width="0.127" layer="21"/>
<wire x1="-5.16" y1="0.9621" x2="-5.16" y2="-0.9467" width="0.127" layer="51"/>
<wire x1="5.1588" y1="0.9621" x2="5.1588" y2="-0.9467" width="0.127" layer="51"/>
<circle x="-6.35" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="6.35" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-6.35" y="0" drill="0.8128" diameter="2.54" shape="octagon"/>
<pad name="2" x="6.35" y="0" drill="0.8128" diameter="2.54" shape="octagon"/>
<text x="-0.4813" y="-0.7958" size="1.6764" layer="27" font="vector">&gt;Value</text>
<text x="-4.9255" y="-0.7144" size="1.6764" layer="25" font="vector">&gt;Name</text>
<text x="4.1268" y="-1.7396" size="0.254" layer="100" font="vector">PaJa</text>
<text x="-4.7625" y="-1.5875" size="0.6096" layer="21" font="vector">2W</text>
<rectangle x1="-5.953" y1="-0.3175" x2="-5.1593" y2="0.3175" layer="51"/>
<rectangle x1="5.1594" y1="-0.3175" x2="5.9531" y2="0.3175" layer="51"/>
</package>
<package name="R-_10W">
<description>&lt;B&gt;Odpor&lt;/B&gt; - 10W - dratovy</description>
<wire x1="-24.13" y1="5.3975" x2="-24.13" y2="-5.3975" width="0.127" layer="21"/>
<wire x1="-24.13" y1="-5.3975" x2="24.13" y2="-5.3975" width="0.127" layer="21"/>
<wire x1="24.13" y1="-5.3975" x2="24.13" y2="5.3975" width="0.127" layer="21"/>
<wire x1="24.13" y1="5.3975" x2="-24.13" y2="5.3975" width="0.127" layer="21"/>
<circle x="-25.7175" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="25.7175" y="0" radius="0.5723" width="0.127" layer="102"/>
<pad name="1" x="-25.7175" y="0" drill="1.016" diameter="2.54" shape="octagon"/>
<pad name="2" x="25.7175" y="0" drill="1.016" diameter="2.54" shape="octagon"/>
<text x="-4.9375" y="-3.08" size="1.9304" layer="27" font="vector">&gt;VALUE</text>
<text x="-4.9375" y="1.2225" size="1.9304" layer="25" font="vector">&gt;NAME</text>
<text x="22.86" y="-5.08" size="0.254" layer="100" font="vector">PaJa</text>
<text x="-23.1775" y="-3.81" size="1.27" layer="21" font="vector">10W</text>
<rectangle x1="-25.2412" y1="-0.635" x2="-24.1299" y2="0.635" layer="51"/>
<rectangle x1="-25.5587" y1="0.4763" x2="-25.2412" y2="0.635" layer="51"/>
<rectangle x1="-25.5587" y1="-0.6349" x2="-25.2412" y2="-0.4762" layer="51"/>
<rectangle x1="24.13" y1="-0.635" x2="25.2413" y2="0.635" layer="51"/>
<rectangle x1="25.2413" y1="-0.6349" x2="25.5588" y2="-0.4762" layer="51"/>
<rectangle x1="25.2413" y1="0.4763" x2="25.5588" y2="0.635" layer="51"/>
</package>
<package name="R-_20W">
<description>&lt;B&gt;Odpor&lt;/B&gt; - 20W - dratovy</description>
<wire x1="30.1625" y1="6.985" x2="-30.1625" y2="6.985" width="0.127" layer="21"/>
<wire x1="30.1625" y1="1.1113" x2="30.1625" y2="-1.1113" width="0.127" layer="51"/>
<wire x1="-30.1626" y1="1.1113" x2="-30.1626" y2="-1.1113" width="0.127" layer="51"/>
<wire x1="-30.1625" y1="1.1113" x2="-30.1625" y2="6.985" width="0.127" layer="21"/>
<wire x1="-30.1625" y1="-1.1113" x2="-30.1625" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-30.1625" y1="-6.985" x2="30.1625" y2="-6.985" width="0.127" layer="21"/>
<wire x1="30.1625" y1="-6.985" x2="30.1625" y2="-1.1113" width="0.127" layer="21"/>
<wire x1="30.1625" y1="6.985" x2="30.1625" y2="1.1113" width="0.127" layer="21"/>
<circle x="-31.75" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="31.75" y="0" radius="0.7099" width="0.127" layer="102"/>
<pad name="1" x="-31.75" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<pad name="2" x="31.75" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<text x="-4.9375" y="-4.6675" size="2.1844" layer="27" font="vector">&gt;VALUE</text>
<text x="-4.9375" y="1.2225" size="2.1844" layer="25" font="vector">&gt;NAME</text>
<text x="28.8925" y="-6.6675" size="0.254" layer="100" font="vector">PaJa</text>
<text x="-29.21" y="-5.715" size="1.27" layer="21" font="vector">20W</text>
<rectangle x1="30.1625" y1="-0.635" x2="31.115" y2="0.635" layer="51"/>
<rectangle x1="-31.1149" y1="-0.635" x2="-30.1624" y2="0.635" layer="51"/>
<rectangle x1="-31.2738" y1="0.4763" x2="-31.115" y2="0.635" layer="51"/>
<rectangle x1="-31.2738" y1="-0.6349" x2="-31.115" y2="-0.4762" layer="51"/>
<rectangle x1="31.115" y1="-0.6349" x2="31.2738" y2="-0.4762" layer="51"/>
<rectangle x1="31.115" y1="0.4763" x2="31.2738" y2="0.635" layer="51"/>
</package>
<package name="R-_5W">
<description>&lt;B&gt;Odpor&lt;/B&gt; - 5W - keramicky</description>
<wire x1="-11.1125" y1="5.08" x2="-11.1125" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-5.08" x2="11.1125" y2="-5.08" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-5.08" x2="11.1125" y2="5.08" width="0.127" layer="21"/>
<wire x1="11.1125" y1="5.08" x2="-11.1125" y2="5.08" width="0.127" layer="21"/>
<circle x="-12.7" y="0" radius="0.5724" width="0.127" layer="102"/>
<circle x="12.7" y="0" radius="0.5723" width="0.127" layer="102"/>
<pad name="1" x="-12.7" y="0" drill="1.016" diameter="2.54" shape="octagon"/>
<pad name="2" x="12.7" y="0" drill="1.016" diameter="2.54" shape="octagon"/>
<text x="-4.9375" y="-3.08" size="1.9304" layer="27" font="vector">&gt;VALUE</text>
<text x="-4.9375" y="1.2225" size="1.9304" layer="25" font="vector">&gt;NAME</text>
<text x="-10.16" y="-3.81" size="1.27" layer="21" font="vector">5W</text>
<text x="9.8425" y="-4.7625" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="-12.2237" y1="-0.635" x2="-11.1124" y2="0.635" layer="51"/>
<rectangle x1="-12.5412" y1="0.4763" x2="-12.2237" y2="0.635" layer="51"/>
<rectangle x1="-12.5412" y1="-0.6349" x2="-12.2237" y2="-0.4762" layer="51"/>
<rectangle x1="11.1125" y1="-0.635" x2="12.2238" y2="0.635" layer="51"/>
<rectangle x1="12.2238" y1="-0.6349" x2="12.5413" y2="-0.4762" layer="51"/>
<rectangle x1="12.2238" y1="0.4763" x2="12.5413" y2="0.635" layer="51"/>
</package>
<package name="R-STOJ">
<description>&lt;B&gt;Odpor&lt;/B&gt; - vel. 0207 - 0,6W - nastojato</description>
<wire x1="-1.905" y1="1.1113" x2="-1.905" y2="-1.1113" width="0.127" layer="21" curve="120.512458"/>
<wire x1="-0.635" y1="1.1113" x2="-0.635" y2="-1.1113" width="0.127" layer="21" curve="-120.512458"/>
<wire x1="-1.905" y1="1.1113" x2="-0.635" y2="1.1113" width="0.127" layer="51" curve="-59.487542"/>
<wire x1="-0.635" y1="-1.1113" x2="-1.905" y2="-1.1113" width="0.127" layer="51" curve="-59.487542"/>
<circle x="-1.27" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="1.27" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-1.27" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<text x="-2.389" y="1.433" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="-2.544" y="-2.385" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="0.636" y="-1.272" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="-0.7938" y1="-0.3175" x2="-0.4763" y2="0.3175" layer="51"/>
<rectangle x1="0.4763" y1="-0.3175" x2="0.7938" y2="0.3175" layer="51"/>
<rectangle x1="-0.4763" y1="-0.3175" x2="0.4763" y2="0.3175" layer="21"/>
</package>
<package name="0805">
<description>&lt;B&gt;SMD&lt;/B&gt; - velikost 0805</description>
<wire x1="-0.3226" y1="0.5645" x2="-0.5645" y2="0.5645" width="0.127" layer="51"/>
<wire x1="-0.5645" y1="0.5645" x2="-0.5645" y2="-0.5645" width="0.127" layer="51"/>
<wire x1="-0.5645" y1="-0.5645" x2="-0.3226" y2="-0.5645" width="0.127" layer="51"/>
<wire x1="0.3226" y1="0.5645" x2="0.5645" y2="0.5645" width="0.127" layer="51"/>
<wire x1="0.5645" y1="0.5645" x2="0.5645" y2="-0.5645" width="0.127" layer="51"/>
<wire x1="0.5645" y1="-0.5645" x2="0.3226" y2="-0.5645" width="0.127" layer="51"/>
<wire x1="-0.3226" y1="0.5645" x2="0.3226" y2="0.5645" width="0.127" layer="21"/>
<wire x1="0.3226" y1="-0.5645" x2="-0.3226" y2="-0.5645" width="0.127" layer="21"/>
<smd name="1" x="-0.9525" y="0" dx="1.016" dy="1.4224" layer="1"/>
<smd name="2" x="0.9525" y="0" dx="1.016" dy="1.4224" layer="1"/>
<text x="-1.397" y="-1.6351" size="0.8128" layer="27" font="vector" ratio="10">&gt;VALUE</text>
<text x="-1.3177" y="0.8413" size="0.8128" layer="25" font="vector" ratio="10">&gt;NAME</text>
<text x="0.3956" y="-0.4763" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="0.4064" y1="-0.6096" x2="0.9144" y2="0.6096" layer="51"/>
<rectangle x1="-0.9144" y1="-0.6096" x2="-0.4064" y2="0.6096" layer="51"/>
</package>
<package name="POJ_KS20">
<wire x1="-11.1125" y1="3.4925" x2="-11.1125" y2="4.7625" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="4.7625" x2="11.1125" y2="4.7625" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-4.7625" x2="-11.1125" y2="-4.7625" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-4.7625" x2="-11.1125" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="3.4925" x2="-5.715" y2="3.4925" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-3.4925" x2="-11.1125" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="-3.4925" y1="3.4925" x2="-3.4925" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-3.4925" x2="-12.7" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="-12.7" y1="-3.4925" x2="-12.7" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-12.7" y1="1.905" x2="-12.7" y2="3.4925" width="0.127" layer="21"/>
<wire x1="-12.7" y1="3.4925" x2="-11.1125" y2="3.4925" width="0.127" layer="21"/>
<wire x1="3.4925" y1="-3.4925" x2="3.4925" y2="3.4925" width="0.127" layer="21"/>
<wire x1="3.4925" y1="3.4925" x2="-3.4925" y2="3.4925" width="0.127" layer="21"/>
<wire x1="-3.4925" y1="-3.4925" x2="3.4925" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="-5.715" y1="3.4925" x2="-5.715" y2="2.8575" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-2.8575" x2="-5.715" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="-5.3975" y1="2.8575" x2="-5.3975" y2="2.54" width="0.127" layer="51"/>
<wire x1="-5.3975" y1="2.54" x2="-5.3975" y2="-2.54" width="0.127" layer="51"/>
<wire x1="-5.3975" y1="-2.54" x2="-5.3975" y2="-2.8575" width="0.127" layer="51"/>
<wire x1="-5.3975" y1="2.8575" x2="-11.1125" y2="2.8575" width="0.127" layer="51"/>
<wire x1="-11.1125" y1="2.8575" x2="-11.1125" y2="-2.8575" width="0.127" layer="51"/>
<wire x1="-11.1125" y1="-2.8575" x2="-5.3975" y2="-2.8575" width="0.127" layer="51"/>
<wire x1="12.3825" y1="3.4925" x2="12.3825" y2="1.905" width="0.127" layer="21"/>
<wire x1="12.3825" y1="-1.905" x2="12.3825" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="5.3975" y1="2.54" x2="5.3975" y2="2.8575" width="0.127" layer="51"/>
<wire x1="-5.3975" y1="2.54" x2="5.3975" y2="2.54" width="0.127" layer="51"/>
<wire x1="5.715" y1="2.8575" x2="5.715" y2="3.4925" width="0.127" layer="21"/>
<wire x1="5.715" y1="3.4925" x2="11.1125" y2="3.4925" width="0.127" layer="21"/>
<wire x1="11.1125" y1="3.4925" x2="12.3825" y2="3.4925" width="0.127" layer="21"/>
<wire x1="5.3975" y1="2.54" x2="5.3975" y2="-2.54" width="0.127" layer="51"/>
<wire x1="5.3975" y1="-2.54" x2="5.3975" y2="-2.8575" width="0.127" layer="51"/>
<wire x1="5.715" y1="-2.8575" x2="5.715" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="5.715" y1="-3.4925" x2="11.1125" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-3.4925" x2="12.3825" y2="-3.4925" width="0.127" layer="21"/>
<wire x1="5.3975" y1="2.8575" x2="11.1125" y2="2.8575" width="0.127" layer="51"/>
<wire x1="11.1125" y1="2.8575" x2="11.1125" y2="-2.8575" width="0.127" layer="51"/>
<wire x1="11.1125" y1="-2.8575" x2="5.3975" y2="-2.8575" width="0.127" layer="51"/>
<wire x1="5.3975" y1="-2.54" x2="-5.3975" y2="-2.54" width="0.127" layer="51"/>
<wire x1="-11.1125" y1="1.905" x2="-12.7" y2="1.905" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-1.905" x2="-12.7" y2="-1.905" width="0.127" layer="21"/>
<wire x1="11.1125" y1="1.905" x2="12.3825" y2="1.905" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-1.905" x2="12.3825" y2="-1.905" width="0.127" layer="21"/>
<wire x1="11.1125" y1="4.7625" x2="11.1125" y2="3.4925" width="0.127" layer="21"/>
<wire x1="11.1125" y1="1.905" x2="11.1125" y2="0.635" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-0.635" x2="11.1125" y2="-1.905" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-3.4925" x2="11.1125" y2="-4.7625" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="1.905" x2="-11.1125" y2="2.8575" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="2.8575" x2="-5.715" y2="2.8575" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-1.905" x2="-11.1125" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-2.8575" x2="-5.715" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="5.715" y1="2.8575" x2="11.1125" y2="2.8575" width="0.127" layer="21"/>
<wire x1="11.1125" y1="2.8575" x2="11.1125" y2="1.905" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-1.905" x2="11.1125" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="11.1125" y1="-2.8575" x2="5.715" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="0.635" x2="-11.1125" y2="1.905" width="0.127" layer="21"/>
<wire x1="-11.1125" y1="-0.635" x2="-11.1125" y2="-1.905" width="0.127" layer="21"/>
<circle x="-11.43" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="11.43" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="0" y="0" radius="1.5875" width="0.127" layer="21"/>
<pad name="1" x="-11.43" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<pad name="2" x="11.43" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<text x="-7.9375" y="5.08" size="1.6764" layer="25" font="vector">&gt;Name</text>
<text x="1.27" y="5.08" size="1.6764" layer="27" font="vector">&gt;Value</text>
<text x="12.065" y="-3.175" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<text x="-6.6675" y="-4.445" size="0.6096" layer="101" font="vector">Pojistkove pouzdro KS20-01</text>
</package>
<package name="POJ_SHH">
<wire x1="-5.715" y1="2.8575" x2="-10.795" y2="2.8575" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-2.8575" x2="-10.795" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="-10.795" y1="2.8575" x2="-10.795" y2="0.9525" width="0.127" layer="21"/>
<wire x1="-10.795" y1="-0.9525" x2="-10.795" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-2.8575" x2="-5.715" y2="-0.9525" width="0.127" layer="21"/>
<wire x1="-5.715" y1="0.9525" x2="-5.715" y2="2.8575" width="0.127" layer="21"/>
<wire x1="-10.795" y1="-2.8575" x2="-14.605" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="-10.16" y1="-2.2225" x2="-5.08" y2="-2.2225" width="0.127" layer="21"/>
<wire x1="5.08" y1="-2.2225" x2="10.16" y2="-2.2225" width="0.127" layer="21"/>
<wire x1="5.715" y1="-0.9525" x2="5.715" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="5.715" y1="-2.8575" x2="10.795" y2="-2.8575" width="0.127" layer="21"/>
<wire x1="10.795" y1="-2.8575" x2="10.795" y2="-0.9525" width="0.127" layer="21"/>
<wire x1="5.715" y1="0.9525" x2="5.715" y2="2.8575" width="0.127" layer="21"/>
<wire x1="5.715" y1="2.8575" x2="10.795" y2="2.8575" width="0.127" layer="21"/>
<wire x1="10.795" y1="2.8575" x2="10.795" y2="2.2225" width="0.127" layer="21"/>
<wire x1="10.795" y1="2.2225" x2="10.795" y2="0.9525" width="0.127" layer="21"/>
<wire x1="-10.16" y1="2.2225" x2="-5.08" y2="2.2225" width="0.127" layer="21"/>
<wire x1="5.08" y1="2.2225" x2="10.16" y2="2.2225" width="0.127" layer="21"/>
<wire x1="10.795" y1="2.2225" x2="14.605" y2="2.2225" width="0.127" layer="21"/>
<wire x1="-10.795" y1="0.9525" x2="-10.795" y2="-0.9525" width="0.127" layer="51"/>
<wire x1="-5.715" y1="0.9525" x2="-5.715" y2="-0.9525" width="0.127" layer="51"/>
<wire x1="5.715" y1="0.9525" x2="5.715" y2="-0.9525" width="0.127" layer="51"/>
<wire x1="10.795" y1="0.9525" x2="10.795" y2="-0.9525" width="0.127" layer="51"/>
<wire x1="-10.16" y1="2.2225" x2="-10.16" y2="-2.2225" width="0.127" layer="21"/>
<wire x1="10.16" y1="2.2225" x2="10.16" y2="-2.2225" width="0.127" layer="21"/>
<wire x1="-5.08" y1="2.2225" x2="-5.08" y2="2.0638" width="0.127" layer="21"/>
<wire x1="-5.08" y1="2.0638" x2="5.08" y2="2.0638" width="0.127" layer="21"/>
<wire x1="5.08" y1="2.0638" x2="5.08" y2="2.2225" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-2.2225" x2="-5.08" y2="-2.0637" width="0.127" layer="21"/>
<wire x1="-5.08" y1="-2.0637" x2="5.08" y2="-2.0637" width="0.127" layer="21"/>
<wire x1="5.08" y1="-2.0637" x2="5.08" y2="-2.2225" width="0.127" layer="21"/>
<wire x1="-5.08" y1="2.0638" x2="-5.08" y2="-2.0637" width="0.127" layer="21"/>
<wire x1="5.08" y1="2.0638" x2="5.08" y2="-2.0637" width="0.127" layer="21"/>
<circle x="-10.795" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="-5.715" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="5.715" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="10.795" y="0" radius="0.7099" width="0.127" layer="102"/>
<pad name="L1" x="-10.795" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<pad name="L2" x="-5.715" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<pad name="P2" x="5.715" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<pad name="P1" x="10.795" y="0" drill="1.27" diameter="3.2" shape="octagon"/>
<text x="-3.1795" y="0.1595" size="1.4224" layer="25" font="vector">&gt;Name</text>
<text x="-3.4977" y="-1.7488" size="1.4224" layer="27" font="vector">&gt;Value</text>
<text x="9.683" y="-2.704" size="0.254" layer="100" font="vector">PaJa</text>
<text x="-3.81" y="2.3813" size="0.8128" layer="101" font="vector">Pojistkove</text>
<text x="-2.54" y="-3.0162" size="0.8128" layer="101" font="vector">pouzdro</text>
</package>
<package name="POJ_TR5">
<description>&lt;b&gt;FUSE&lt;/b&gt;&lt;p&gt;
Wickmann</description>
<wire x1="-1.8415" y1="0" x2="1.8415" y2="0" width="0.1524" layer="101"/>
<wire x1="-0.9525" y1="0.381" x2="-0.9525" y2="-0.381" width="0.1524" layer="101"/>
<wire x1="-0.9525" y1="-0.381" x2="0.9525" y2="-0.381" width="0.1524" layer="101"/>
<wire x1="0.9525" y1="0.381" x2="0.9525" y2="-0.381" width="0.1524" layer="101"/>
<wire x1="0.9525" y1="0.381" x2="-0.9525" y2="0.381" width="0.1524" layer="101"/>
<circle x="0" y="0" radius="4.318" width="0.1524" layer="21"/>
<circle x="-2.54" y="0" radius="0.449" width="0.127" layer="102"/>
<circle x="2.54" y="0" radius="0.449" width="0.127" layer="102"/>
<pad name="1" x="-2.54" y="0" drill="0.8128" diameter="1.778" shape="long" rot="R90"/>
<pad name="2" x="2.54" y="0" drill="0.8128" diameter="1.778" shape="long" rot="R90"/>
<text x="-1.905" y="2.2225" size="1.27" layer="25" font="vector" ratio="10">&gt;Name</text>
<text x="-2.54" y="-3.175" size="1.27" layer="27" font="vector" ratio="10">&gt;Value</text>
<text x="4.1275" y="-0.3175" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
</package>
<package name="C-EL_2">
<wire x1="-0.1378" y1="-1.02" x2="-0.1378" y2="-1.782" width="0.127" layer="21"/>
<wire x1="-0.5188" y1="-1.401" x2="0.2432" y2="-1.401" width="0.127" layer="21"/>
<wire x1="0.4762" y1="-1.524" x2="0.9842" y2="-1.524" width="0.127" layer="21"/>
<wire x1="0.9842" y1="-1.524" x2="0.9842" y2="1.524" width="0.127" layer="21"/>
<wire x1="0.9842" y1="1.524" x2="0.4762" y2="1.524" width="0.127" layer="21"/>
<wire x1="0.4762" y1="1.524" x2="0.4762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="1.4112" y1="1.5" x2="1.7862" y2="1.5" width="0.127" layer="21"/>
<wire x1="1.7862" y1="1.5" x2="1.7862" y2="-1.5" width="0.127" layer="21"/>
<wire x1="1.7862" y1="-1.5" x2="1.4112" y2="-1.5" width="0.127" layer="21"/>
<wire x1="1.4112" y1="-1.5" x2="1.4112" y2="1.5" width="0.127" layer="21"/>
<wire x1="1.5762" y1="0" x2="2.1962" y2="0" width="0.127" layer="21"/>
<wire x1="0.0262" y1="0" x2="0.2712" y2="0" width="0.127" layer="21"/>
<wire x1="0.2712" y1="0" x2="0.3362" y2="0" width="0.127" layer="21"/>
<wire x1="0.2712" y1="0" x2="0.439" y2="0" width="0.127" layer="21"/>
<circle x="1.1112" y="0" radius="2.4848" width="0.127" layer="21"/>
<circle x="-0.0018" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="2.2242" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="C+" x="0" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<pad name="C-" x="2.2225" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<text x="-1.2738" y="2.544" size="1.27" layer="25" font="vector">&gt;Name</text>
<text x="-1.5918" y="-3.816" size="1.27" layer="27" font="vector">&gt;Value</text>
<text x="0.6342" y="1.908" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="1.4112" y1="-1.5" x2="1.7862" y2="1.425" layer="21"/>
</package>
<package name="C-EL_2,5">
<wire x1="-0.635" y1="-1.524" x2="-0.127" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.127" y1="-1.524" x2="-0.127" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.127" y1="1.524" x2="-0.635" y2="1.524" width="0.127" layer="21"/>
<wire x1="-1.868" y1="-0.861" x2="-1.868" y2="-1.623" width="0.127" layer="21"/>
<wire x1="-2.249" y1="-1.242" x2="-1.487" y2="-1.242" width="0.127" layer="21"/>
<wire x1="-0.635" y1="1.524" x2="-0.635" y2="-1.524" width="0.127" layer="21"/>
<wire x1="0.3" y1="1.5" x2="0.675" y2="1.5" width="0.127" layer="21"/>
<wire x1="0.675" y1="1.5" x2="0.675" y2="-1.5" width="0.127" layer="21"/>
<wire x1="0.675" y1="-1.5" x2="0.3" y2="-1.5" width="0.127" layer="21"/>
<wire x1="0.3" y1="-1.5" x2="0.3" y2="1.5" width="0.127" layer="21"/>
<wire x1="0.62" y1="0" x2="1.24" y2="0" width="0.127" layer="21"/>
<wire x1="-1.24" y1="0" x2="-0.8146" y2="0" width="0.127" layer="21"/>
<wire x1="-0.8146" y1="0" x2="-0.775" y2="0" width="0.127" layer="21"/>
<wire x1="-0.8146" y1="0" x2="-0.6758" y2="0" width="0.127" layer="21"/>
<circle x="0" y="0" radius="3.255" width="0.127" layer="21"/>
<circle x="-1.272" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="1.272" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="C+" x="-1.27" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<pad name="C-" x="1.27" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<text x="-1.431" y="1.59" size="1.27" layer="25" font="vector">&gt;Name</text>
<text x="-1.272" y="-2.862" size="1.27" layer="27" font="vector">&gt;Value</text>
<text x="-0.2447" y="-0.4478" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="0.3" y1="-1.5" x2="0.675" y2="1.425" layer="21"/>
</package>
<package name="C-EL_3,5">
<wire x1="1.1113" y1="-1.524" x2="1.6193" y2="-1.524" width="0.127" layer="21"/>
<wire x1="1.6193" y1="-1.524" x2="1.6193" y2="1.524" width="0.127" layer="21"/>
<wire x1="1.6193" y1="1.524" x2="1.1113" y2="1.524" width="0.127" layer="21"/>
<wire x1="0.1838" y1="-1.1705" x2="0.1838" y2="-1.9325" width="0.127" layer="21"/>
<wire x1="-0.1972" y1="-1.5515" x2="0.5648" y2="-1.5515" width="0.127" layer="21"/>
<wire x1="1.1113" y1="1.524" x2="1.1113" y2="-1.524" width="0.127" layer="21"/>
<wire x1="2.0463" y1="1.5" x2="2.4213" y2="1.5" width="0.127" layer="21"/>
<wire x1="2.4213" y1="1.5" x2="2.4213" y2="-1.5" width="0.127" layer="21"/>
<wire x1="2.4213" y1="-1.5" x2="2.0463" y2="-1.5" width="0.127" layer="21"/>
<wire x1="2.0463" y1="-1.5" x2="2.0463" y2="1.5" width="0.127" layer="21"/>
<wire x1="2.3623" y1="0" x2="2.9783" y2="0" width="0.127" layer="51"/>
<wire x1="0.4747" y1="0" x2="0.9713" y2="0" width="0.127" layer="21"/>
<wire x1="0.5063" y1="0" x2="1.0705" y2="0" width="0.127" layer="51"/>
<circle x="1.7463" y="0.155" radius="4.03" width="0.127" layer="21"/>
<circle x="-0.0027" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="3.4953" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="C+" x="0" y="0" drill="0.8128" diameter="1.9304"/>
<pad name="C-" x="3.4925" y="0" drill="0.8128" diameter="1.9304" shape="square"/>
<text x="-0.6476" y="-2.9909" size="1.27" layer="27" font="vector">&gt;VALUE</text>
<text x="4.7965" y="3.0261" size="1.27" layer="25" font="vector" rot="R180">&gt;NAME</text>
<text x="2.7003" y="1.113" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="2.0463" y1="-1.5" x2="2.4213" y2="1.425" layer="21"/>
</package>
<package name="C-EL_5">
<wire x1="-0.762" y1="-1.524" x2="-0.254" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="1.524" x2="-0.762" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.762" y1="1.524" x2="-0.762" y2="0" width="0.127" layer="21"/>
<wire x1="0.635" y1="0" x2="1.2065" y2="0" width="0.127" layer="21"/>
<wire x1="-0.762" y1="0" x2="-1.236" y2="0" width="0.127" layer="21"/>
<wire x1="-0.762" y1="0" x2="-0.762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-2.003" y1="0" x2="-1.236" y2="0" width="0.127" layer="51"/>
<wire x1="1.2325" y1="0" x2="2.003" y2="0" width="0.127" layer="51"/>
<wire x1="-1.905" y1="-1.27" x2="-1.27" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-1.5875" y1="-0.9525" x2="-1.5875" y2="-1.5875" width="0.127" layer="21"/>
<circle x="0" y="0" radius="5.1308" width="0.127" layer="21"/>
<circle x="-2.54" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="2.54" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="C-" x="2.54" y="0" drill="0.8128" diameter="2.1844" shape="square"/>
<pad name="C+" x="-2.54" y="0" drill="0.8128" diameter="2.1844"/>
<text x="1.272" y="0.318" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<text x="-3.017" y="1.758" size="1.4224" layer="25" font="vector">&gt;Name</text>
<text x="-3.663" y="-3.186" size="1.4224" layer="27" font="vector">&gt;Value</text>
<rectangle x1="0.254" y1="-1.524" x2="0.762" y2="1.524" layer="21"/>
</package>
<package name="C-EL_5+">
<wire x1="-0.762" y1="-1.524" x2="-0.254" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="1.524" x2="-0.762" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.762" y1="1.524" x2="-0.762" y2="0" width="0.127" layer="21"/>
<wire x1="0.635" y1="0" x2="1.0478" y2="0" width="0.127" layer="21"/>
<wire x1="-0.762" y1="0" x2="-1.0478" y2="0" width="0.127" layer="21"/>
<wire x1="-0.762" y1="0" x2="-0.762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-2.003" y1="0" x2="-1.0775" y2="0" width="0.127" layer="51"/>
<wire x1="1.0738" y1="0" x2="2.003" y2="0" width="0.127" layer="51"/>
<wire x1="-2.019" y1="-1.5655" x2="-1.081" y2="-1.5655" width="0.127" layer="21"/>
<wire x1="-1.55" y1="-1.0965" x2="-1.55" y2="-2.0345" width="0.127" layer="21"/>
<circle x="0" y="0" radius="6.519" width="0.127" layer="21"/>
<circle x="-2.544" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="2.544" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="C+" x="-2.54" y="0" drill="0.8128" diameter="2.54"/>
<pad name="C-" x="2.54" y="0" drill="0.8128" diameter="2.54" shape="square"/>
<text x="-4.299" y="-3.663" size="1.6764" layer="27" font="vector">&gt;VALUE</text>
<text x="-3.653" y="1.758" size="1.6764" layer="25" font="vector">&gt;NAME</text>
<text x="1.113" y="0.318" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="0.254" y1="-1.524" x2="0.762" y2="1.524" layer="21"/>
</package>
<package name="C-EL_7,5">
<wire x1="-0.762" y1="-1.524" x2="-0.254" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="1.524" x2="-0.762" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.762" y1="1.524" x2="-0.762" y2="0" width="0.127" layer="21"/>
<wire x1="0.635" y1="0" x2="2.343" y2="0" width="0.127" layer="21"/>
<wire x1="-0.762" y1="0" x2="-2.347" y2="0" width="0.127" layer="21"/>
<wire x1="-0.762" y1="0" x2="-0.762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-3.275" y1="0" x2="-2.347" y2="0" width="0.127" layer="51"/>
<wire x1="2.343" y1="0" x2="3.275" y2="0" width="0.127" layer="51"/>
<wire x1="-2.54" y1="-0.7938" x2="-2.54" y2="-1.7463" width="0.127" layer="21"/>
<wire x1="-3.0163" y1="-1.27" x2="-2.0638" y2="-1.27" width="0.127" layer="21"/>
<circle x="0" y="0" radius="8.1339" width="0.127" layer="21"/>
<circle x="-3.816" y="0" radius="0.5732" width="0.127" layer="102"/>
<circle x="3.816" y="0" radius="0.5732" width="0.127" layer="102"/>
<pad name="C-" x="3.81" y="0" drill="1.016" diameter="2.54" shape="square"/>
<pad name="C+" x="-3.81" y="0" drill="1.016" diameter="2.54"/>
<text x="-4.458" y="-3.981" size="1.778" layer="27" font="vector">&gt;VALUE</text>
<text x="-3.812" y="2.076" size="1.778" layer="25" font="vector">&gt;NAME</text>
<text x="1.113" y="0.159" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="0.254" y1="-1.524" x2="0.762" y2="1.524" layer="21"/>
</package>
<package name="C-EL7,5+">
<wire x1="-0.762" y1="-1.524" x2="-0.254" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="1.524" x2="-0.762" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.762" y1="1.524" x2="-0.762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-2.6558" y1="-1.089" x2="-1.7178" y2="-1.089" width="0.127" layer="21"/>
<wire x1="-2.1868" y1="-0.62" x2="-2.1868" y2="-1.558" width="0.127" layer="21"/>
<wire x1="-2.3813" y1="0" x2="-3.175" y2="0" width="0.127" layer="51"/>
<wire x1="2.3813" y1="0" x2="3.175" y2="0" width="0.127" layer="51"/>
<wire x1="-2.3813" y1="0" x2="-0.7938" y2="0" width="0.127" layer="21"/>
<wire x1="0.635" y1="0" x2="2.3813" y2="0" width="0.127" layer="21"/>
<circle x="0" y="0" radius="9.063" width="0.127" layer="21"/>
<circle x="-3.816" y="0" radius="0.5732" width="0.127" layer="102"/>
<circle x="3.816" y="0" radius="0.5732" width="0.127" layer="102"/>
<pad name="C-" x="3.81" y="0" drill="1.016" diameter="2.54" shape="square"/>
<pad name="C+" x="-3.81" y="0" drill="1.016" diameter="2.54"/>
<text x="-4.458" y="-3.981" size="1.778" layer="27" font="vector">&gt;VALUE</text>
<text x="-3.812" y="2.076" size="1.778" layer="25" font="vector">&gt;NAME</text>
<text x="1.113" y="0.159" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="0.254" y1="-1.524" x2="0.762" y2="1.524" layer="21"/>
</package>
<package name="C-EL_10">
<wire x1="-0.762" y1="-1.524" x2="-0.254" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="1.524" x2="-0.762" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.762" y1="1.524" x2="-0.762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="0.635" y1="0" x2="3.3338" y2="0" width="0.127" layer="21"/>
<wire x1="-0.7938" y1="0" x2="-3.3338" y2="0" width="0.127" layer="21"/>
<wire x1="-3.3338" y1="-1.1113" x2="-2.0638" y2="-1.1113" width="0.127" layer="21"/>
<wire x1="-2.6988" y1="-0.4763" x2="-2.6988" y2="-1.7463" width="0.127" layer="21"/>
<wire x1="3.3338" y1="0" x2="4.2863" y2="0" width="0.127" layer="51"/>
<wire x1="-3.3338" y1="0" x2="-4.2863" y2="0" width="0.127" layer="51"/>
<circle x="0" y="0" radius="11.1125" width="0.127" layer="21"/>
<circle x="-5.08" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="5.08" y="0" radius="0.7099" width="0.127" layer="102"/>
<pad name="C-" x="5.08" y="0" drill="1.27" diameter="3.2" shape="square"/>
<pad name="C+" x="-5.08" y="0" drill="1.27" diameter="3.2"/>
<text x="-5.728" y="-4.9335" size="2.1844" layer="27" font="vector">&gt;VALUE</text>
<text x="-4.7645" y="3.0285" size="2.1844" layer="25" font="vector">&gt;NAME</text>
<text x="1.113" y="0.159" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="0.254" y1="-1.524" x2="0.762" y2="1.524" layer="21"/>
</package>
<package name="C-EL_10+">
<wire x1="-0.762" y1="-1.524" x2="-0.254" y2="-1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.254" y1="1.524" x2="-0.762" y2="1.524" width="0.127" layer="21"/>
<wire x1="-0.762" y1="1.524" x2="-0.762" y2="-1.524" width="0.127" layer="21"/>
<wire x1="0.635" y1="0" x2="3.1751" y2="0" width="0.127" layer="21"/>
<wire x1="-0.7938" y1="0" x2="-3.175" y2="0" width="0.127" layer="21"/>
<wire x1="-3.3338" y1="-1.1113" x2="-2.0638" y2="-1.1113" width="0.127" layer="21"/>
<wire x1="-2.6988" y1="-0.4763" x2="-2.6988" y2="-1.7463" width="0.127" layer="21"/>
<wire x1="3.175" y1="0" x2="4.2863" y2="0" width="0.127" layer="51"/>
<wire x1="-3.175" y1="0" x2="-4.2863" y2="0" width="0.127" layer="51"/>
<circle x="-5.08" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="5.08" y="0" radius="0.7099" width="0.127" layer="102"/>
<circle x="0" y="0" radius="15.24" width="0.254" layer="21"/>
<pad name="C-" x="5.08" y="0" drill="1.27" diameter="3.2" shape="square"/>
<pad name="C+" x="-5.08" y="0" drill="1.27" diameter="3.2"/>
<text x="-5.728" y="-5.886" size="2.1844" layer="27" font="vector">&gt;VALUE</text>
<text x="-4.7645" y="3.0285" size="2.1844" layer="25" font="vector">&gt;NAME</text>
<text x="1.113" y="0.159" size="0.254" layer="100" font="vector">PaJa</text>
<rectangle x1="0.254" y1="-1.524" x2="0.762" y2="1.524" layer="21"/>
</package>
<package name="C-2,5">
<circle x="-1.272" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="1.272" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="1" x="-1.27" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="0.8128" diameter="1.27" shape="long" rot="R90"/>
<text x="-1.6704" y="1.3513" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="-1.6709" y="-2.3853" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="0.159" y="0.318" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="-0.5556" y1="-1.27" x2="-0.1746" y2="1.27" layer="21"/>
<rectangle x1="0.1746" y1="-1.27" x2="0.5556" y2="1.27" layer="21"/>
<rectangle x1="-0.7938" y1="-0.1588" x2="-0.5556" y2="0.1588" layer="51"/>
<rectangle x1="0.5556" y1="-0.1588" x2="0.7938" y2="0.1588" layer="51"/>
</package>
<package name="C-5">
<circle x="-2.544" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="2.544" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="1" x="-2.54" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<pad name="2" x="2.54" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<text x="0.795" y="0.954" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="0.795" y="-1.9085" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="0.159" y="0.3182" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="-0.7143" y1="-1.27" x2="-0.238" y2="1.27" layer="21"/>
<rectangle x1="0.2381" y1="-1.27" x2="0.7144" y2="1.27" layer="21"/>
<rectangle x1="-2.0638" y1="-0.1588" x2="-1.4288" y2="0.1588" layer="51"/>
<rectangle x1="1.4288" y1="-0.1588" x2="2.0638" y2="0.1588" layer="51"/>
<rectangle x1="-1.4288" y1="-0.1588" x2="-0.635" y2="0.1588" layer="21"/>
<rectangle x1="0.635" y1="-0.1588" x2="1.4288" y2="0.1588" layer="21"/>
</package>
<package name="C-7,5">
<circle x="-3.814" y="0" radius="0.477" width="0.127" layer="102"/>
<circle x="3.814" y="0" radius="0.477" width="0.127" layer="102"/>
<pad name="1" x="-3.81" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<pad name="2" x="3.81" y="0" drill="0.8128" diameter="1.9304" shape="octagon"/>
<text x="0.795" y="0.954" size="1.016" layer="25" font="vector">&gt;Name</text>
<text x="0.795" y="-1.9085" size="1.016" layer="27" font="vector">&gt;Value</text>
<text x="0.159" y="0.477" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<rectangle x1="-0.7155" y1="-1.431" x2="-0.2385" y2="1.431" layer="21"/>
<rectangle x1="0.2385" y1="-1.431" x2="0.7155" y2="1.431" layer="21"/>
<rectangle x1="-2.6988" y1="-0.1588" x2="-0.635" y2="0.1588" layer="21"/>
<rectangle x1="0.635" y1="-0.1588" x2="2.6988" y2="0.1588" layer="21"/>
<rectangle x1="-3.3338" y1="-0.1588" x2="-2.6988" y2="0.1588" layer="51"/>
<rectangle x1="2.6988" y1="-0.1588" x2="3.3338" y2="0.1588" layer="51"/>
</package>
<package name="C-10">
<wire x1="-6.35" y1="2.6035" x2="-6.35" y2="-2.6035" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-2.6035" x2="6.35" y2="-2.6035" width="0.127" layer="21"/>
<wire x1="6.35" y1="-2.6035" x2="6.35" y2="2.6035" width="0.127" layer="21"/>
<wire x1="6.35" y1="2.6035" x2="-6.35" y2="2.6035" width="0.127" layer="21"/>
<circle x="-5.08" y="0" radius="0.4763" width="0.127" layer="102"/>
<circle x="5.08" y="0" radius="0.4762" width="0.127" layer="102"/>
<pad name="1" x="-5.08" y="0" drill="0.8128" diameter="2.1844" shape="octagon"/>
<pad name="2" x="5.08" y="0" drill="0.8128" diameter="2.1844" shape="octagon"/>
<text x="0.159" y="0.3182" size="0.254" layer="100" font="vector" rot="R90">PaJa</text>
<text x="-4.0444" y="1.1525" size="1.27" layer="25" font="vector">&gt;Name</text>
<text x="-4.3507" y="-2.4225" size="1.27" layer="27" font="vector">&gt;Value</text>
<rectangle x1="-0.7144" y1="-1.27" x2="-0.2381" y2="1.27" layer="21"/>
<rectangle x1="0.238" y1="-1.27" x2="0.7143" y2="1.27" layer="21"/>
<rectangle x1="-4.6038" y1="-0.1588" x2="-3.81" y2="0.1588" layer="51"/>
<rectangle x1="3.81" y1="-0.1588" x2="4.6038" y2="0.1588" layer="51"/>
<rectangle x1="-3.81" y1="-0.1588" x2="-0.635" y2="0.1588" layer="21"/>
<rectangle x1="0.635" y1="-0.1588" x2="3.81" y2="0.1588" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="T-PNP">
<wire x1="0" y1="-2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<wire x1="2.544" y1="-2.544" x2="0.3175" y2="0" width="0.1524" layer="94"/>
<wire x1="0.3175" y1="0" x2="0.4763" y2="0.1588" width="0.1524" layer="94"/>
<wire x1="0.4763" y1="0.1588" x2="0.4768" y2="0.1588" width="0.1524" layer="94"/>
<wire x1="0.4768" y1="0.1588" x2="2.544" y2="2.544" width="0.1524" layer="94"/>
<wire x1="0.4768" y1="0.1588" x2="1.4288" y2="0.3175" width="0.1524" layer="94"/>
<wire x1="0.4768" y1="0.1588" x2="0.6358" y2="1.1128" width="0.1524" layer="94"/>
<wire x1="0.635" y1="1.1113" x2="0.635" y2="0.3175" width="0.1524" layer="94"/>
<wire x1="0.635" y1="0.3175" x2="1.4288" y2="0.3175" width="0.1524" layer="94"/>
<circle x="1.27" y="0.0001" radius="3.5921" width="0.1524" layer="94"/>
<text x="5.08" y="1.27" size="1.778" layer="95">&gt;Name</text>
<text x="5.08" y="-3.81" size="1.778" layer="96">&gt;Value</text>
<text x="1.27" y="-3.81" size="1.27" layer="101" rot="MR180">c</text>
<text x="-3.818" y="-0.167" size="1.27" layer="101" rot="MR180">b</text>
<text x="1.437" y="5.086" size="1.27" layer="101" rot="MR180">e</text>
<text x="-1.431" y="-0.159" size="0.254" layer="100" rot="MR180">PaJa</text>
<pin name="E" x="2.54" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="C" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="B" x="-5.08" y="0" visible="off" length="middle" direction="pas"/>
</symbol>
<symbol name="D-ZENERK">
<wire x1="-0.1588" y1="1.27" x2="-0.1588" y2="0" width="0.254" layer="94"/>
<wire x1="-0.1588" y1="0" x2="-0.1588" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-2.3813" y1="-1.27" x2="-2.3813" y2="1.27" width="0.254" layer="94"/>
<wire x1="-2.3813" y1="1.27" x2="-0.1588" y2="0" width="0.254" layer="94"/>
<wire x1="-0.1588" y1="0" x2="-2.3813" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-0.1588" y1="1.27" x2="-0.635" y2="1.27" width="0.254" layer="94"/>
<text x="-2.2227" y="0.4759" size="0.254" layer="100" rot="R270">PaJa</text>
<text x="-2.5401" y="-1.905" size="1.6764" layer="96" rot="MR180">&gt;Value</text>
<text x="-2.54" y="1.905" size="1.6764" layer="95">&gt;Part</text>
<pin name="A" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
<pin name="K" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="R">
<wire x1="-2.54" y1="1.0319" x2="2.54" y2="1.0319" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.0319" x2="2.54" y2="-1.0319" width="0.254" layer="94"/>
<wire x1="2.54" y1="-1.0319" x2="-2.54" y2="-1.0319" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-1.0319" x2="-2.54" y2="1.0319" width="0.254" layer="94"/>
<text x="2.3815" y="-0.476" size="0.254" layer="100" rot="R90">PaJa</text>
<text x="-2.2225" y="1.5875" size="1.6764" layer="95">&gt;Name</text>
<text x="-2.2225" y="-1.5875" size="1.6764" layer="96" rot="MR180">&gt;Value</text>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="+12V">
<wire x1="-1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-2.5399" x2="0" y2="0" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="-0.635" x2="0" y2="1.27" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="1.27" y2="-0.635" width="0.254" layer="94"/>
<text x="0.9525" y="1.905" size="1.778" layer="96" rot="R90">&gt;Value</text>
<text x="1.27" y="-5.3975" size="1.016" layer="101" ratio="6" rot="R90">+12V</text>
<text x="-0.1588" y="-1.905" size="0.254" layer="100" rot="R90">PaJa</text>
<pin name="+12V" x="0" y="-5.08" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND">
<wire x1="-1.7463" y1="-0.0001" x2="1.7463" y2="-0.0001" width="0.6096" layer="94"/>
<text x="-1.1113" y="0.3175" size="0.254" layer="100">PaJa</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="POJISTKA">
<wire x1="-2.54" y1="1.0319" x2="2.54" y2="1.0319" width="0.254" layer="94"/>
<wire x1="2.54" y1="1.0319" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-1.0319" width="0.254" layer="94"/>
<wire x1="2.54" y1="-1.0319" x2="-2.54" y2="-1.0319" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-1.0319" x2="-2.54" y2="0" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.54" y2="1.0319" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="2.54" y2="0" width="0.152" layer="94"/>
<text x="1.4676" y="-0.8595" size="0.254" layer="100">PaJa</text>
<text x="-2.5401" y="-1.5875" size="1.6764" layer="96" rot="MR180">&gt;Value</text>
<text x="-2.54" y="1.5875" size="1.6764" layer="95">&gt;Name</text>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="C-EL">
<wire x1="-3.8173" y1="0.9547" x2="-2.5453" y2="0.9547" width="0.155" layer="94"/>
<wire x1="-3.1812" y1="1.5908" x2="-3.1812" y2="0.3188" width="0.155" layer="94"/>
<wire x1="-2.0638" y1="1.7463" x2="-1.4288" y2="1.7463" width="0.254" layer="94"/>
<wire x1="-1.4288" y1="1.7463" x2="-1.4288" y2="-1.5875" width="0.254" layer="94"/>
<wire x1="-1.4288" y1="-1.5875" x2="-2.0638" y2="-1.5875" width="0.254" layer="94"/>
<wire x1="-2.0638" y1="-1.5875" x2="-2.0638" y2="0" width="0.254" layer="94"/>
<wire x1="-2.0638" y1="0" x2="-2.0638" y2="1.7463" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-2.0638" y2="0" width="0.152" layer="94"/>
<wire x1="-0.4763" y1="0" x2="0" y2="0" width="0.152" layer="94"/>
<text x="-1.589" y="-0.477" size="0.254" layer="100" rot="R90">PaJa</text>
<text x="0.3175" y="0.635" size="1.6764" layer="95">&gt;Name</text>
<text x="0.3175" y="-0.635" size="1.6764" layer="96" rot="MR180">&gt;Value</text>
<rectangle x1="-0.9525" y1="-1.7463" x2="-0.3175" y2="1.905" layer="94"/>
<pin name="C_EL+" x="-5.08" y="0" visible="off" length="short" direction="pas"/>
<pin name="C_EL-" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="C">
<wire x1="-2.54" y1="0" x2="-2.0638" y2="0" width="0.152" layer="94"/>
<wire x1="-0.4763" y1="0" x2="0" y2="0" width="0.152" layer="94"/>
<text x="-1.111" y="-0.479" size="0.254" layer="100" rot="R90">PaJa</text>
<text x="0.3175" y="0.635" size="1.6764" layer="95">&gt;Name</text>
<text x="0.3175" y="-0.635" size="1.6764" layer="96" rot="MR180">&gt;Value</text>
<rectangle x1="-2.2225" y1="-1.905" x2="-1.5875" y2="1.905" layer="94"/>
<rectangle x1="-0.9525" y1="-1.905" x2="-0.3175" y2="1.905" layer="94"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="2" x="2.54" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="BC327" prefix="T">
<description>&lt;B&gt;Tranzistor PNP&lt;/B&gt; - Univerzalni NF - Ic=0,5A</description>
<gates>
<gate name="T" symbol="T-PNP" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TO-92">
<connects>
<connect gate="T" pin="B" pad="2"/>
<connect gate="T" pin="C" pad="1"/>
<connect gate="T" pin="E" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="D-ZENEROVA" prefix="DZ">
<description>&lt;B&gt;Zenerova dioda&lt;/B&gt;</description>
<gates>
<gate name="DZ" symbol="D-ZENERK" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="_0,5W_BZX83V" package="DO35">
<connects>
<connect gate="DZ" pin="A" pad="A"/>
<connect gate="DZ" pin="K" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_1,3W_BZX85V" package="DO35">
<connects>
<connect gate="DZ" pin="A" pad="A"/>
<connect gate="DZ" pin="K" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_2W_BZY" package="DO41">
<connects>
<connect gate="DZ" pin="A" pad="A"/>
<connect gate="DZ" pin="K" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_0,5W_BZV55C_SMD" package="SOD-80">
<connects>
<connect gate="DZ" pin="A" pad="A"/>
<connect gate="DZ" pin="K" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_0,35W_BZX84C_SMD" package="SOT-23">
<connects>
<connect gate="DZ" pin="A" pad="1"/>
<connect gate="DZ" pin="K" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_5W_1N53XX" package="DO201">
<connects>
<connect gate="DZ" pin="A" pad="A"/>
<connect gate="DZ" pin="K" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="R" prefix="R" uservalue="yes">
<description>&lt;b&gt;Rezistor&lt;/b&gt;</description>
<gates>
<gate name="R" symbol="R" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="_5" package="R-5">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_10" package="R-10">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_12,7" package="R-12,7">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_7,5" package="R-7,5">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_SMD_1206" package="1206">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="__2W" package="R-_2W">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="__10W" package="R-_10W">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="__20W" package="R-_20W">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="__5W" package="R-_5W">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_STOJ" package="R-STOJ">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_SMD_0805" package="0805">
<connects>
<connect gate="R" pin="1" pad="1"/>
<connect gate="R" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+12V" prefix="NAP">
<description>&lt;B&gt;SCH symbol&lt;/B&gt; - napajeni +12V</description>
<gates>
<gate name="+12" symbol="+12V" x="0" y="-5.08"/>
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
<description>&lt;B&gt;SCH symbol&lt;/B&gt; - zem - &lt;I&gt;GrouND&lt;/I&gt;</description>
<gates>
<gate name="ZEM" symbol="GND" x="-45.72" y="35.56"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="POJISTKY" prefix="POJ">
<description>&lt;B&gt;Pojistkove pouzdro&lt;/B&gt;</description>
<gates>
<gate name="POJ" symbol="POJISTKA" x="-45.72" y="38.1"/>
</gates>
<devices>
<device name="KS20" package="POJ_KS20">
<connects>
<connect gate="POJ" pin="1" pad="1"/>
<connect gate="POJ" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="SHH" package="POJ_SHH">
<connects>
<connect gate="POJ" pin="1" pad="L1"/>
<connect gate="POJ" pin="2" pad="P1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="RADIAL" package="POJ_TR5">
<connects>
<connect gate="POJ" pin="1" pad="1"/>
<connect gate="POJ" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="C-ELEKTROLYT" prefix="C" uservalue="yes">
<description>&lt;b&gt;Kondenzator - elektrolyticky&lt;/b&gt;</description>
<gates>
<gate name="C" symbol="C-EL" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="_2" package="C-EL_2">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_2,5" package="C-EL_2,5">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_3,5" package="C-EL_3,5">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_5" package="C-EL_5">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_5+" package="C-EL_5+">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_7,5" package="C-EL_7,5">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_7,5+" package="C-EL7,5+">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_10" package="C-EL_10">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_10+" package="C-EL_10+">
<connects>
<connect gate="C" pin="C_EL+" pad="C+"/>
<connect gate="C" pin="C_EL-" pad="C-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="C-KERAMIK" prefix="C" uservalue="yes">
<description>&lt;b&gt;Kondenzator - keramicky&lt;/b&gt;</description>
<gates>
<gate name="C" symbol="C" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="_2,5" package="C-2,5">
<connects>
<connect gate="C" pin="1" pad="1"/>
<connect gate="C" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_5" package="C-5">
<connects>
<connect gate="C" pin="1" pad="1"/>
<connect gate="C" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_7,5" package="C-7,5">
<connects>
<connect gate="C" pin="1" pad="1"/>
<connect gate="C" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_10" package="C-10">
<connects>
<connect gate="C" pin="1" pad="1"/>
<connect gate="C" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_SMD_1206" package="1206">
<connects>
<connect gate="C" pin="1" pad="1"/>
<connect gate="C" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="_SMD_0805" package="0805">
<connects>
<connect gate="C" pin="1" pad="1"/>
<connect gate="C" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="transistor-power">
<description>&lt;b&gt;Power Transistors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="TO220BV">
<description>&lt;b&gt;Molded Package&lt;/b&gt;&lt;p&gt;
grid 2.54 mm</description>
<wire x1="4.699" y1="-4.318" x2="4.953" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="4.699" y1="-4.318" x2="-4.699" y2="-4.318" width="0.1524" layer="21"/>
<wire x1="-4.953" y1="-4.064" x2="-4.699" y2="-4.318" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.143" x2="4.953" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="-4.953" y1="-4.064" x2="-5.08" y2="-1.143" width="0.1524" layer="21"/>
<circle x="-4.4958" y="-3.7084" radius="0.254" width="0" layer="21"/>
<pad name="G" x="-2.54" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<pad name="D" x="0" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<pad name="S" x="2.54" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<text x="-5.08" y="-6.0452" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-7.62" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-5.334" y1="-0.762" x2="5.334" y2="0" layer="21"/>
<rectangle x1="-5.334" y1="-1.27" x2="-3.429" y2="-0.762" layer="21"/>
<rectangle x1="-1.651" y1="-1.27" x2="-0.889" y2="-0.762" layer="21"/>
<rectangle x1="-3.429" y1="-1.27" x2="-1.651" y2="-0.762" layer="51"/>
<rectangle x1="0.889" y1="-1.27" x2="1.651" y2="-0.762" layer="21"/>
<rectangle x1="3.429" y1="-1.27" x2="5.334" y2="-0.762" layer="21"/>
<rectangle x1="-0.889" y1="-1.27" x2="0.889" y2="-0.762" layer="51"/>
<rectangle x1="1.651" y1="-1.27" x2="3.429" y2="-0.762" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="MFNS">
<wire x1="-1.1176" y1="2.413" x2="-1.1176" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-1.1176" y1="-2.54" x2="-2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="1.905" x2="0.5334" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="0.508" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="1.905" x2="5.08" y2="1.905" width="0.1524" layer="94"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="0.762" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0.762" x2="5.08" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="5.08" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0.762" x2="4.445" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="4.445" y1="-0.635" x2="5.715" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="5.715" y1="-0.635" x2="5.08" y2="0.762" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0.762" x2="5.08" y2="0.762" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0.762" x2="5.715" y2="0.762" width="0.1524" layer="94"/>
<wire x1="5.715" y1="0.762" x2="5.969" y2="1.016" width="0.1524" layer="94"/>
<wire x1="4.445" y1="0.762" x2="4.191" y2="0.508" width="0.1524" layer="94"/>
<wire x1="0.508" y1="0" x2="1.778" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="1.778" y1="-0.508" x2="1.778" y2="0.508" width="0.1524" layer="94"/>
<wire x1="1.778" y1="0.508" x2="0.508" y2="0" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0.254" x2="0.762" y2="0" width="0.3048" layer="94"/>
<wire x1="0.762" y1="0" x2="1.651" y2="-0.254" width="0.3048" layer="94"/>
<wire x1="1.651" y1="-0.254" x2="1.651" y2="0" width="0.3048" layer="94"/>
<wire x1="1.651" y1="0" x2="1.397" y2="0" width="0.3048" layer="94"/>
<circle x="2.54" y="-1.905" radius="0.127" width="0.4064" layer="94"/>
<circle x="2.54" y="1.905" radius="0.127" width="0.4064" layer="94"/>
<text x="7.62" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="7.62" y="0" size="1.778" layer="96">&gt;VALUE</text>
<text x="1.27" y="2.54" size="0.8128" layer="93">D</text>
<text x="1.27" y="-3.175" size="0.8128" layer="93">S</text>
<text x="-2.54" y="-1.27" size="0.8128" layer="93">G</text>
<rectangle x1="-0.254" y1="-2.54" x2="0.508" y2="-1.27" layer="94"/>
<rectangle x1="-0.254" y1="1.27" x2="0.508" y2="2.54" layer="94"/>
<rectangle x1="-0.254" y1="-0.889" x2="0.508" y2="0.889" layer="94"/>
<pin name="G" x="-2.54" y="-2.54" visible="off" length="point" direction="pas"/>
<pin name="D" x="2.54" y="5.08" visible="off" length="short" direction="pas" rot="R270"/>
<pin name="S" x="2.54" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="IRF520" prefix="Q">
<description>&lt;b&gt;HEXFET Power MOSFET&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="MFNS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="TO220BV">
<connects>
<connect gate="G$1" pin="D" pad="D"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="S" pad="S"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="#Svorkovnice">
<description>&lt;B&gt;Vlada&lt;/B&gt; - knihovna  
&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp; &lt;I&gt;vytvoreno 2.2.2005&lt;/I&gt;&lt;BR&gt;
Univerzalni knihovna soucastek do Eagle &lt;I&gt;(od verze 4.13)&lt;/I&gt;&lt;BR&gt;
&lt;BR&gt;

&lt;Author&gt;Copyright (C) Vlada 2004-2005&lt;BR&gt;</description>
<packages>
<package name="AK500/2">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<wire x1="-5.08" y1="-3.556" x2="-5.08" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="5.08" y1="3.937" x2="-5.08" y2="3.937" width="0.1524" layer="21"/>
<wire x1="5.08" y1="3.937" x2="5.08" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-3.556" x2="5.08" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="3.048" x2="-5.588" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="3.048" x2="-5.08" y2="3.937" width="0.1524" layer="21"/>
<wire x1="-5.588" y1="3.175" x2="-5.588" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-5.588" y1="2.032" x2="-5.08" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="2.159" x2="-5.08" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="2.159" x2="5.08" y2="2.159" width="0.1524" layer="21"/>
<wire x1="5.08" y1="2.159" x2="5.08" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-2.159" x2="5.08" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-2.159" x2="-5.08" y2="2.159" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-2.159" x2="5.08" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="1.4986" y1="-1.397" x2="3.9116" y2="1.016" width="0.1524" layer="51"/>
<wire x1="1.1176" y1="-1.016" x2="3.5306" y2="1.397" width="0.1524" layer="51"/>
<wire x1="-3.9116" y1="-1.016" x2="-1.4986" y2="1.397" width="0.1524" layer="51"/>
<wire x1="-3.5306" y1="-1.397" x2="-1.1176" y2="1.016" width="0.1524" layer="51"/>
<wire x1="1.4986" y1="-1.016" x2="3.5306" y2="1.016" width="0.6096" layer="51"/>
<wire x1="-3.5306" y1="-1.016" x2="-1.4986" y2="1.016" width="0.6096" layer="51"/>
<wire x1="1.1176" y1="-1.016" x2="1.4986" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="3.5306" y1="1.397" x2="3.9116" y2="1.016" width="0.1524" layer="51"/>
<wire x1="-3.9116" y1="-1.016" x2="-3.5306" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="-1.4986" y1="1.397" x2="-1.1176" y2="1.016" width="0.1524" layer="51"/>
<circle x="2.5146" y="3.048" radius="0.508" width="0.1524" layer="21"/>
<circle x="-2.5146" y="3.048" radius="0.508" width="0.1524" layer="21"/>
<circle x="2.5146" y="0" radius="1.778" width="0.1524" layer="51"/>
<circle x="-2.5146" y="0" radius="1.778" width="0.1524" layer="51"/>
<pad name="1" x="-2.5146" y="0" drill="1.3208" shape="long" rot="R90"/>
<pad name="2" x="2.5146" y="0" drill="1.3208" shape="long" rot="R90"/>
<text x="-5.08" y="4.445" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-5.715" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-4.445" y="2.54" size="0.9906" layer="21" ratio="12">1</text>
<text x="0.635" y="2.54" size="0.9906" layer="21" ratio="12">2</text>
<rectangle x1="-0.381" y1="-1.905" x2="0.381" y2="1.905" layer="21"/>
</package>
<package name="AK500/4">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<wire x1="-10.0838" y1="-3.556" x2="-10.0838" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="-3.556" x2="0" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="3.048" x2="-10.5918" y2="3.175" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="3.048" x2="-10.0838" y2="3.937" width="0.1524" layer="21"/>
<wire x1="-10.5918" y1="3.175" x2="-10.5918" y2="2.032" width="0.1524" layer="21"/>
<wire x1="-10.5918" y1="2.032" x2="-10.0838" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="2.159" x2="-10.0838" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="2.159" x2="0" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="-2.159" x2="0" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-10.0838" y1="-2.159" x2="-10.0838" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-3.5052" y1="-1.397" x2="-1.0922" y2="1.016" width="0.1524" layer="51"/>
<wire x1="-3.8862" y1="-1.016" x2="-1.4732" y2="1.397" width="0.1524" layer="51"/>
<wire x1="-8.9154" y1="-1.016" x2="-6.5024" y2="1.397" width="0.1524" layer="51"/>
<wire x1="-8.5344" y1="-1.397" x2="-6.1214" y2="1.016" width="0.1524" layer="51"/>
<wire x1="-3.5052" y1="-1.016" x2="-1.4732" y2="1.016" width="0.6096" layer="51"/>
<wire x1="-8.5344" y1="-1.016" x2="-6.5024" y2="1.016" width="0.6096" layer="51"/>
<wire x1="-3.8862" y1="-1.016" x2="-3.5052" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="-1.4732" y1="1.397" x2="-1.0922" y2="1.016" width="0.1524" layer="51"/>
<wire x1="-8.9154" y1="-1.016" x2="-8.5344" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="-6.5024" y1="1.397" x2="-6.1214" y2="1.016" width="0.1524" layer="51"/>
<wire x1="0" y1="-3.556" x2="0" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="10.0838" y1="3.937" x2="0" y2="3.937" width="0.1524" layer="21"/>
<wire x1="10.0838" y1="3.937" x2="10.0838" y2="2.159" width="0.1524" layer="21"/>
<wire x1="0" y1="-3.556" x2="10.0838" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="0" y1="2.159" x2="0" y2="3.937" width="0.1524" layer="21"/>
<wire x1="0" y1="2.159" x2="10.0838" y2="2.159" width="0.1524" layer="21"/>
<wire x1="10.0838" y1="2.159" x2="10.0838" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="0" y1="-2.159" x2="10.0838" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="0" y1="-2.159" x2="0" y2="2.159" width="0.1524" layer="21"/>
<wire x1="10.0838" y1="-2.159" x2="10.0838" y2="-3.556" width="0.1524" layer="21"/>
<wire x1="6.5024" y1="-1.397" x2="8.9154" y2="1.016" width="0.1524" layer="51"/>
<wire x1="6.1214" y1="-1.016" x2="8.5344" y2="1.397" width="0.1524" layer="51"/>
<wire x1="1.0922" y1="-1.016" x2="3.5052" y2="1.397" width="0.1524" layer="51"/>
<wire x1="1.4732" y1="-1.397" x2="3.8862" y2="1.016" width="0.1524" layer="51"/>
<wire x1="6.5024" y1="-1.016" x2="8.5344" y2="1.016" width="0.6096" layer="51"/>
<wire x1="1.4732" y1="-1.016" x2="3.5052" y2="1.016" width="0.6096" layer="51"/>
<wire x1="6.1214" y1="-1.016" x2="6.5024" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="8.5344" y1="1.397" x2="8.9154" y2="1.016" width="0.1524" layer="51"/>
<wire x1="1.0922" y1="-1.016" x2="1.4732" y2="-1.397" width="0.1524" layer="51"/>
<wire x1="3.5052" y1="1.397" x2="3.8862" y2="1.016" width="0.1524" layer="51"/>
<wire x1="0" y1="3.937" x2="-10.0838" y2="3.937" width="0.1524" layer="21"/>
<circle x="-2.4892" y="3.048" radius="0.508" width="0.1524" layer="21"/>
<circle x="-7.5184" y="3.048" radius="0.508" width="0.1524" layer="21"/>
<circle x="-2.4892" y="0" radius="1.778" width="0.1524" layer="51"/>
<circle x="-7.5184" y="0" radius="1.778" width="0.1524" layer="51"/>
<circle x="7.5184" y="3.048" radius="0.508" width="0.1524" layer="21"/>
<circle x="2.4892" y="3.048" radius="0.508" width="0.1524" layer="21"/>
<circle x="7.5184" y="0" radius="1.778" width="0.1524" layer="51"/>
<circle x="2.4892" y="0" radius="1.778" width="0.1524" layer="51"/>
<pad name="1" x="-7.5184" y="0" drill="1.3208" shape="long" rot="R90"/>
<pad name="2" x="-2.4892" y="0" drill="1.3208" shape="long" rot="R90"/>
<pad name="3" x="2.4892" y="0" drill="1.3208" shape="long" rot="R90"/>
<pad name="4" x="7.5184" y="0" drill="1.3208" shape="long" rot="R90"/>
<text x="-10.0838" y="4.445" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.0838" y="-5.715" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-9.144" y="2.54" size="0.9906" layer="21" ratio="12">1</text>
<text x="-4.191" y="2.54" size="0.9906" layer="21" ratio="12">2</text>
<text x="0.762" y="2.54" size="0.9906" layer="21" ratio="12">3</text>
<text x="5.842" y="2.54" size="0.9906" layer="21" ratio="12">4</text>
<rectangle x1="-5.3848" y1="-1.905" x2="-4.6228" y2="1.905" layer="21"/>
<rectangle x1="4.6228" y1="-1.905" x2="5.3848" y2="1.905" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="KL">
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="-1.27" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="KLV">
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="-1.27" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<text x="-3.81" y="-3.683" size="1.778" layer="96">&gt;VALUE</text>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="AK500/2" prefix="CON" uservalue="yes">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="-1" symbol="KL" x="0" y="5.08" addlevel="always"/>
<gate name="-2" symbol="KLV" x="0" y="0" addlevel="always"/>
</gates>
<devices>
<device name="" package="AK500/2">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-2" pin="KL" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="AK500/4" prefix="CON" uservalue="yes">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="-1" symbol="KL" x="0" y="12.7" addlevel="always"/>
<gate name="-2" symbol="KL" x="0" y="7.62" addlevel="always"/>
<gate name="-3" symbol="KL" x="0" y="2.54" addlevel="always"/>
<gate name="-4" symbol="KLV" x="0" y="-2.54" addlevel="always"/>
</gates>
<devices>
<device name="" package="AK500/4">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-2" pin="KL" pad="2"/>
<connect gate="-3" pin="KL" pad="3"/>
<connect gate="-4" pin="KL" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="linear">
<description>&lt;b&gt;Linear Devices&lt;/b&gt;&lt;p&gt;
Operational amplifiers,  comparators, voltage regulators, ADCs, DACs, etc.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="TO92">
<description>&lt;b&gt;TO-92&lt;/b&gt;</description>
<wire x1="-2.095" y1="-1.651" x2="-0.7869" y2="2.5484" width="0.1524" layer="21" curve="-111.097684"/>
<wire x1="0.7869" y1="2.5484" x2="2.095" y2="-1.651" width="0.1524" layer="21" curve="-111.097684"/>
<wire x1="-2.095" y1="-1.651" x2="2.095" y2="-1.651" width="0.1524" layer="21"/>
<wire x1="-2.254" y1="-0.254" x2="-0.286" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-2.655" y1="-0.254" x2="-2.254" y2="-0.254" width="0.1524" layer="21"/>
<wire x1="-0.286" y1="-0.254" x2="0.286" y2="-0.254" width="0.1524" layer="21"/>
<wire x1="2.254" y1="-0.254" x2="2.655" y2="-0.254" width="0.1524" layer="21"/>
<wire x1="0.286" y1="-0.254" x2="2.254" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-0.7864" y1="2.5484" x2="0.7864" y2="2.5484" width="0.1524" layer="51" curve="-34.298964"/>
<pad name="1" x="-1.27" y="0" drill="0.8128" shape="octagon"/>
<pad name="2" x="0" y="1.905" drill="0.8128" shape="octagon"/>
<pad name="3" x="1.27" y="0" drill="0.8128" shape="octagon"/>
<text x="2.413" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="2.921" y="-1.27" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="TO220H">
<description>&lt;b&gt;TO-220&lt;/b&gt;</description>
<wire x1="-5.207" y1="-7.62" x2="5.207" y2="-7.62" width="0.1524" layer="21"/>
<wire x1="5.207" y1="8.255" x2="-5.207" y2="8.255" width="0.1524" layer="21"/>
<wire x1="5.207" y1="-7.62" x2="5.207" y2="4.826" width="0.1524" layer="21"/>
<wire x1="5.207" y1="4.826" x2="4.318" y2="4.826" width="0.1524" layer="21"/>
<wire x1="4.318" y1="4.826" x2="4.318" y2="6.35" width="0.1524" layer="21"/>
<wire x1="4.318" y1="6.35" x2="5.207" y2="6.35" width="0.1524" layer="21"/>
<wire x1="5.207" y1="6.35" x2="5.207" y2="8.255" width="0.1524" layer="21"/>
<wire x1="-5.207" y1="-7.62" x2="-5.207" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-5.207" y1="4.826" x2="-4.318" y2="4.826" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="4.826" x2="-4.318" y2="6.35" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="6.35" x2="-5.207" y2="6.35" width="0.1524" layer="21"/>
<wire x1="-5.207" y1="6.35" x2="-5.207" y2="8.255" width="0.1524" layer="21"/>
<wire x1="-4.572" y1="-6.985" x2="4.572" y2="-6.985" width="0.0508" layer="21"/>
<wire x1="4.572" y1="1.27" x2="4.572" y2="-6.985" width="0.0508" layer="21"/>
<wire x1="4.572" y1="1.27" x2="-4.572" y2="1.27" width="0.0508" layer="21"/>
<wire x1="-4.572" y1="-6.985" x2="-4.572" y2="1.27" width="0.0508" layer="21"/>
<circle x="0" y="4.826" radius="1.8034" width="0.1524" layer="21"/>
<circle x="0" y="4.826" radius="2.54" width="0" layer="43"/>
<circle x="0" y="4.826" radius="2.54" width="0" layer="42"/>
<pad name="1" x="-2.54" y="-10.16" drill="1.1176" shape="long" rot="R90"/>
<pad name="2" x="0" y="-10.16" drill="1.1176" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="-10.16" drill="1.1176" shape="long" rot="R90"/>
<text x="-5.461" y="-10.922" size="1.778" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="7.366" y="-11.049" size="1.778" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="2.159" y1="-11.049" x2="2.921" y2="-10.414" layer="21"/>
<rectangle x1="-0.381" y1="-11.049" x2="0.381" y2="-10.414" layer="21"/>
<rectangle x1="-2.921" y1="-11.049" x2="-2.159" y2="-10.414" layer="21"/>
<rectangle x1="-3.175" y1="-10.414" x2="-1.905" y2="-7.62" layer="21"/>
<rectangle x1="-0.635" y1="-10.414" x2="0.635" y2="-7.62" layer="21"/>
<rectangle x1="1.905" y1="-10.414" x2="3.175" y2="-7.62" layer="21"/>
<hole x="0" y="4.826" drill="3.302"/>
</package>
<package name="TO39">
<description>&lt;b&gt;Metal Can Package&lt;/b&gt;</description>
<wire x1="-4.0386" y1="-3.5306" x2="-3.5052" y2="-2.9972" width="0.1524" layer="21"/>
<wire x1="-2.9718" y1="-3.5306" x2="-3.5052" y2="-4.064" width="0.1524" layer="21"/>
<wire x1="-3.5052" y1="-4.064" x2="-4.0386" y2="-3.5306" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="4.572" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="3.8608" width="0.0508" layer="21"/>
<pad name="1" x="0" y="-2.54" drill="0.8128" shape="octagon"/>
<pad name="2" x="2.54" y="0" drill="0.8128" shape="octagon"/>
<pad name="3" x="0" y="2.54" drill="0.8128" shape="octagon"/>
<text x="-2.794" y="4.826" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.302" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="TO252">
<description>&lt;b&gt;SMALL OUTLINE TRANSISTOR&lt;/b&gt;&lt;p&gt;
TS-003</description>
<wire x1="3.2766" y1="3.8354" x2="3.277" y2="-2.159" width="0.2032" layer="21"/>
<wire x1="3.277" y1="-2.159" x2="-3.277" y2="-2.159" width="0.2032" layer="21"/>
<wire x1="-3.277" y1="-2.159" x2="-3.2766" y2="3.8354" width="0.2032" layer="21"/>
<wire x1="-3.277" y1="3.835" x2="3.2774" y2="3.8346" width="0.2032" layer="51"/>
<wire x1="-2.5654" y1="3.937" x2="-2.5654" y2="4.6482" width="0.2032" layer="51"/>
<wire x1="-2.5654" y1="4.6482" x2="-2.1082" y2="5.1054" width="0.2032" layer="51"/>
<wire x1="-2.1082" y1="5.1054" x2="2.1082" y2="5.1054" width="0.2032" layer="51"/>
<wire x1="2.1082" y1="5.1054" x2="2.5654" y2="4.6482" width="0.2032" layer="51"/>
<wire x1="2.5654" y1="4.6482" x2="2.5654" y2="3.937" width="0.2032" layer="51"/>
<wire x1="2.5654" y1="3.937" x2="-2.5654" y2="3.937" width="0.2032" layer="51"/>
<smd name="3" x="0" y="2.5" dx="5.4" dy="6.2" layer="1"/>
<smd name="1" x="-2.28" y="-4.8" dx="1" dy="1.6" layer="1"/>
<smd name="2" x="2.28" y="-4.8" dx="1" dy="1.6" layer="1"/>
<text x="-3.81" y="-2.54" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="5.08" y="-2.54" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.7178" y1="-5.1562" x2="-1.8542" y2="-2.2606" layer="51"/>
<rectangle x1="1.8542" y1="-5.1562" x2="2.7178" y2="-2.2606" layer="51"/>
<rectangle x1="-0.4318" y1="-3.0226" x2="0.4318" y2="-2.2606" layer="21"/>
<polygon width="0.1998" layer="51">
<vertex x="-2.5654" y="3.937"/>
<vertex x="-2.5654" y="4.6482"/>
<vertex x="-2.1082" y="5.1054"/>
<vertex x="2.1082" y="5.1054"/>
<vertex x="2.5654" y="4.6482"/>
<vertex x="2.5654" y="3.937"/>
</polygon>
</package>
<package name="TO220V">
<description>&lt;b&gt;TO 200 vertical&lt;/b&gt;</description>
<wire x1="5.08" y1="-1.143" x2="4.953" y2="-4.064" width="0.127" layer="21"/>
<wire x1="4.699" y1="-4.318" x2="4.953" y2="-4.064" width="0.127" layer="21"/>
<wire x1="4.699" y1="-4.318" x2="-4.699" y2="-4.318" width="0.127" layer="21"/>
<wire x1="-4.953" y1="-4.064" x2="-4.699" y2="-4.318" width="0.127" layer="21"/>
<wire x1="-4.953" y1="-4.064" x2="-5.08" y2="-1.143" width="0.127" layer="21"/>
<circle x="-4.4958" y="-3.7084" radius="0.254" width="0.127" layer="21"/>
<pad name="1" x="-2.54" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="0" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="-2.54" drill="1.016" shape="long" rot="R90"/>
<text x="-5.08" y="-6.0452" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-7.62" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="-3.175" y="-3.175" size="1.27" layer="51" ratio="10">1</text>
<text x="-0.635" y="-3.175" size="1.27" layer="51" ratio="10">2</text>
<text x="1.905" y="-3.175" size="1.27" layer="51" ratio="10">3</text>
<rectangle x1="-5.334" y1="-0.762" x2="5.334" y2="0" layer="21"/>
<rectangle x1="-5.334" y1="-1.27" x2="-3.429" y2="-0.762" layer="21"/>
<rectangle x1="-1.651" y1="-1.27" x2="-0.889" y2="-0.762" layer="21"/>
<rectangle x1="-3.429" y1="-1.27" x2="-1.651" y2="-0.762" layer="51"/>
<rectangle x1="0.889" y1="-1.27" x2="1.651" y2="-0.762" layer="21"/>
<rectangle x1="3.429" y1="-1.27" x2="5.334" y2="-0.762" layer="21"/>
<rectangle x1="-0.889" y1="-1.27" x2="0.889" y2="-0.762" layer="51"/>
<rectangle x1="1.651" y1="-1.27" x2="3.429" y2="-0.762" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="78XX">
<wire x1="-7.62" y1="-5.08" x2="7.62" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="7.62" y2="2.54" width="0.4064" layer="94"/>
<wire x1="7.62" y1="2.54" x2="-7.62" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-7.62" y1="2.54" x2="-7.62" y2="-5.08" width="0.4064" layer="94"/>
<text x="-7.62" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="3.175" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.032" y="-4.318" size="1.524" layer="95">GND</text>
<pin name="VI" x="-10.16" y="0" length="short" direction="in"/>
<pin name="GND" x="0" y="-7.62" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="VO" x="10.16" y="0" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="78*" prefix="IC">
<description>Positive &lt;b&gt;VOLTAGE REGULATOR&lt;/b&gt;&lt;p&gt;
Source:&lt;br&gt;
http://cache.national.com/ds/LM/LM78L05.pdf&lt;br&gt;
http://www.fairchildsemi.com/ds/LM/LM7805.pdf</description>
<gates>
<gate name="A1" symbol="78XX" x="0" y="0"/>
</gates>
<devices>
<device name="Z" package="TO92">
<connects>
<connect gate="A1" pin="GND" pad="2"/>
<connect gate="A1" pin="VI" pad="3"/>
<connect gate="A1" pin="VO" pad="1"/>
</connects>
<technologies>
<technology name="L05"/>
<technology name="L08"/>
<technology name="L12"/>
<technology name="L15"/>
<technology name="L18"/>
<technology name="L24"/>
</technologies>
</device>
<device name="T" package="TO220H">
<connects>
<connect gate="A1" pin="GND" pad="2"/>
<connect gate="A1" pin="VI" pad="1"/>
<connect gate="A1" pin="VO" pad="3"/>
</connects>
<technologies>
<technology name="05"/>
<technology name="06"/>
<technology name="08"/>
<technology name="12"/>
<technology name="15"/>
<technology name="18"/>
<technology name="24"/>
</technologies>
</device>
<device name="H" package="TO39">
<connects>
<connect gate="A1" pin="GND" pad="3"/>
<connect gate="A1" pin="VI" pad="1"/>
<connect gate="A1" pin="VO" pad="2"/>
</connects>
<technologies>
<technology name="05"/>
<technology name="06"/>
<technology name="08"/>
<technology name="12"/>
<technology name="15"/>
<technology name="18"/>
<technology name="24"/>
</technologies>
</device>
<device name="L" package="TO92">
<connects>
<connect gate="A1" pin="GND" pad="2"/>
<connect gate="A1" pin="VI" pad="3"/>
<connect gate="A1" pin="VO" pad="1"/>
</connects>
<technologies>
<technology name="05"/>
<technology name="06"/>
<technology name="08"/>
<technology name="12"/>
<technology name="15"/>
<technology name="18"/>
<technology name="24"/>
</technologies>
</device>
<device name="DT" package="TO252">
<connects>
<connect gate="A1" pin="GND" pad="3"/>
<connect gate="A1" pin="VI" pad="1"/>
<connect gate="A1" pin="VO" pad="2"/>
</connects>
<technologies>
<technology name="05"/>
<technology name="06"/>
<technology name="08"/>
<technology name="12"/>
<technology name="15"/>
<technology name="18"/>
<technology name="24"/>
</technologies>
</device>
<device name="TV" package="TO220V">
<connects>
<connect gate="A1" pin="GND" pad="2"/>
<connect gate="A1" pin="VI" pad="1"/>
<connect gate="A1" pin="VO" pad="3"/>
</connects>
<technologies>
<technology name="05"/>
<technology name="12"/>
<technology name="15"/>
<technology name="18"/>
<technology name="24"/>
<technology name="6"/>
<technology name="8"/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="#Led">
<description>&lt;B&gt;Vlada&lt;/B&gt; - knihovna  
&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp; &lt;I&gt;vytvoreno 2.2.2005&lt;/I&gt;&lt;BR&gt;
Univerzalni knihovna soucastek do Eagle &lt;I&gt;(od verze 4.13)&lt;/I&gt;&lt;BR&gt;
&lt;BR&gt;

&lt;Author&gt;Copyright (C) Vlada 2004-2005&lt;BR&gt;</description>
<packages>
<package name="LED3MM">
<description>&lt;B&gt;LED&lt;/B&gt;&lt;p&gt;
3 mm, round</description>
<wire x1="1.5748" y1="-1.27" x2="1.5748" y2="1.27" width="0.254" layer="51"/>
<wire x1="-1.524" y1="0" x2="-1.1708" y2="0.9756" width="0.1524" layer="51" curve="-39.80361" cap="flat"/>
<wire x1="-1.524" y1="0" x2="-1.1391" y2="-1.0125" width="0.1524" layer="51" curve="41.633208" cap="flat"/>
<wire x1="1.1571" y1="0.9918" x2="1.524" y2="0" width="0.1524" layer="51" curve="-40.601165" cap="flat"/>
<wire x1="1.1708" y1="-0.9756" x2="1.524" y2="0" width="0.1524" layer="51" curve="39.80361" cap="flat"/>
<wire x1="0" y1="1.524" x2="1.2401" y2="0.8858" width="0.1524" layer="21" curve="-54.461337" cap="flat"/>
<wire x1="-1.2192" y1="0.9144" x2="0" y2="1.524" width="0.1524" layer="21" curve="-53.130102" cap="flat"/>
<wire x1="0" y1="-1.524" x2="1.203" y2="-0.9356" width="0.1524" layer="21" curve="52.126876" cap="flat"/>
<wire x1="-1.203" y1="-0.9356" x2="0" y2="-1.524" width="0.1524" layer="21" curve="52.126876" cap="flat"/>
<wire x1="-0.635" y1="0" x2="0" y2="0.635" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="-1.016" y1="0" x2="0" y2="1.016" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-0.635" x2="0.635" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="-1.016" x2="1.016" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.032" x2="1.561" y2="1.3009" width="0.254" layer="21" curve="-50.193108" cap="flat"/>
<wire x1="-1.7929" y1="0.9562" x2="0" y2="2.032" width="0.254" layer="21" curve="-61.926949" cap="flat"/>
<wire x1="0" y1="-2.032" x2="1.5512" y2="-1.3126" width="0.254" layer="21" curve="49.763022" cap="flat"/>
<wire x1="-1.7643" y1="-1.0082" x2="0" y2="-2.032" width="0.254" layer="21" curve="60.255215" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7891" y2="0.9634" width="0.254" layer="51" curve="-28.301701" cap="flat"/>
<wire x1="-2.032" y1="0" x2="-1.7306" y2="-1.065" width="0.254" layer="51" curve="31.60822" cap="flat"/>
<pad name="A" x="-1.27" y="0" drill="0.8" diameter="1.9304" shape="octagon"/>
<pad name="K" x="1.27" y="0" drill="0.8" diameter="1.9304" shape="octagon"/>
<text x="1.905" y="0.381" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="1.905" y="-1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="LED5MM">
<description>&lt;B&gt;LED&lt;/B&gt;&lt;p&gt;
5 mm, round</description>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="1.905" width="0.2032" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="1.905" width="0.254" layer="21" curve="-286.260205" cap="flat"/>
<wire x1="-1.143" y1="0" x2="0" y2="1.143" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-1.143" x2="1.143" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="-1.651" y1="0" x2="0" y2="1.651" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-1.651" x2="1.651" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<wire x1="-2.159" y1="0" x2="0" y2="2.159" width="0.1524" layer="51" curve="-90" cap="flat"/>
<wire x1="0" y1="-2.159" x2="2.159" y2="0" width="0.1524" layer="51" curve="90" cap="flat"/>
<circle x="0" y="0" radius="2.54" width="0.1524" layer="21"/>
<pad name="A" x="-1.27" y="0" drill="0.8" diameter="1.9304" shape="octagon"/>
<pad name="K" x="1.27" y="0" drill="0.8" diameter="1.9304" shape="octagon"/>
<text x="3.175" y="0.5334" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="3.2004" y="-1.8034" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="LED">
<wire x1="1.27" y1="0" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="-2.54" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="-2.032" y1="-0.762" x2="-3.429" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="-3.302" y2="-3.302" width="0.1524" layer="94"/>
<text x="3.556" y="-4.318" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.715" y="-4.318" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="C" x="0" y="-5.08" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="A" x="0" y="2.54" visible="pad" length="short" direction="pas" rot="R270"/>
<polygon width="0.1524" layer="94">
<vertex x="-3.429" y="-2.159"/>
<vertex x="-3.048" y="-1.27"/>
<vertex x="-2.54" y="-1.778"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-3.302" y="-3.302"/>
<vertex x="-2.921" y="-2.413"/>
<vertex x="-2.413" y="-2.921"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="LED" prefix="D" uservalue="yes">
<gates>
<gate name="G$1" symbol="LED" x="0" y="0"/>
</gates>
<devices>
<device name="LED3MM" package="LED3MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="LED5MM" package="LED5MM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="K"/>
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
<part name="T1" library="#PaJa_30" deviceset="BC327" device=""/>
<part name="IRF3205" library="transistor-power" deviceset="IRF520" device=""/>
<part name="DZ1" library="#PaJa_30" deviceset="D-ZENEROVA" device="_2W_BZY" value="10V"/>
<part name="R1" library="#PaJa_30" deviceset="R" device="_10" value="100k"/>
<part name="GND2" library="#PaJa_30" deviceset="GND" device=""/>
<part name="R2" library="#PaJa_30" deviceset="R" device="_10" value="10k"/>
<part name="NAP2" library="#PaJa_30" deviceset="+12V" device=""/>
<part name="TLACITKO" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="POJ1" library="#PaJa_30" deviceset="POJISTKY" device="KS20"/>
<part name="BAT" library="#Svorkovnice" deviceset="AK500/4" device=""/>
<part name="SWITCH_PRIMARY" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="CHARGE" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="NAP1" library="#PaJa_30" deviceset="+12V" device=""/>
<part name="GND1" library="#PaJa_30" deviceset="GND" device=""/>
<part name="C1" library="#PaJa_30" deviceset="C-ELEKTROLYT" device="_7,5+"/>
<part name="IC1" library="linear" deviceset="78*" device="TV" technology="05"/>
<part name="SWITCH_MOTOR" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="MOTOR_POWER" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="C2" library="#PaJa_30" deviceset="C-KERAMIK" device="_5" value="0.33uF"/>
<part name="C3" library="#PaJa_30" deviceset="C-KERAMIK" device="_5" value="0.1uF"/>
<part name="SWITCH-SICK" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="SICK_POWER" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="RASP_POWER" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="MD22_POWER" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="DEKODER_POWER" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="FREE" library="#Svorkovnice" deviceset="AK500/2" device=""/>
<part name="D1" library="#Led" deviceset="LED" device="LED5MM"/>
<part name="R3" library="#PaJa_30" deviceset="R" device="_10" value="150"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="T1" gate="T" x="66.04" y="38.1" rot="MR0"/>
<instance part="IRF3205" gate="G$1" x="104.14" y="27.94"/>
<instance part="DZ1" gate="DZ" x="81.28" y="38.1" smashed="yes" rot="R180">
<attribute name="VALUE" x="83.8201" y="40.005" size="1.6764" layer="96" rot="MR0"/>
<attribute name="PART" x="83.82" y="36.195" size="1.6764" layer="95" rot="R180"/>
</instance>
<instance part="R1" gate="R" x="99.06" y="38.1"/>
<instance part="GND2" gate="ZEM" x="114.3" y="43.18" rot="R90"/>
<instance part="R2" gate="R" x="63.5" y="17.78" rot="R90"/>
<instance part="NAP2" gate="+12" x="114.3" y="50.8" rot="R270"/>
<instance part="TLACITKO" gate="-1" x="43.18" y="20.32"/>
<instance part="TLACITKO" gate="-2" x="43.18" y="15.24"/>
<instance part="POJ1" gate="POJ" x="33.02" y="50.8" smashed="yes">
<attribute name="VALUE" x="27.9399" y="49.2125" size="1.6764" layer="96" rot="MR180"/>
<attribute name="NAME" x="30.48" y="52.3875" size="1.6764" layer="95"/>
</instance>
<instance part="BAT" gate="-1" x="12.7" y="25.4"/>
<instance part="BAT" gate="-2" x="12.7" y="30.48"/>
<instance part="BAT" gate="-3" x="12.7" y="35.56"/>
<instance part="BAT" gate="-4" x="12.7" y="40.64"/>
<instance part="SWITCH_PRIMARY" gate="-1" x="45.72" y="63.5" rot="R270"/>
<instance part="SWITCH_PRIMARY" gate="-2" x="40.64" y="63.5" rot="R270"/>
<instance part="CHARGE" gate="-1" x="35.56" y="25.4" rot="R180"/>
<instance part="CHARGE" gate="-2" x="35.56" y="30.48" rot="R180"/>
<instance part="NAP1" gate="+12" x="20.32" y="127" rot="R90"/>
<instance part="GND1" gate="ZEM" x="22.86" y="111.76" rot="R270"/>
<instance part="C1" gate="C" x="35.56" y="116.84" rot="R270"/>
<instance part="IC1" gate="A1" x="119.38" y="127"/>
<instance part="SWITCH_MOTOR" gate="-1" x="58.42" y="139.7" rot="R270"/>
<instance part="SWITCH_MOTOR" gate="-2" x="63.5" y="139.7" rot="R270"/>
<instance part="MOTOR_POWER" gate="-1" x="45.72" y="139.7" rot="R270"/>
<instance part="MOTOR_POWER" gate="-2" x="50.8" y="139.7" rot="R270"/>
<instance part="C2" gate="C" x="106.68" y="119.38" rot="R90"/>
<instance part="C3" gate="C" x="134.62" y="119.38" rot="R90"/>
<instance part="SWITCH-SICK" gate="-1" x="88.9" y="139.7" rot="R270"/>
<instance part="SWITCH-SICK" gate="-2" x="93.98" y="139.7" rot="R270"/>
<instance part="SICK_POWER" gate="-1" x="76.2" y="139.7" rot="R270"/>
<instance part="SICK_POWER" gate="-2" x="81.28" y="139.7" rot="R270"/>
<instance part="RASP_POWER" gate="-1" x="180.34" y="139.7" rot="R270"/>
<instance part="RASP_POWER" gate="-2" x="175.26" y="139.7" rot="R270"/>
<instance part="MD22_POWER" gate="-1" x="195.58" y="139.7" rot="R270"/>
<instance part="MD22_POWER" gate="-2" x="190.5" y="139.7" rot="R270"/>
<instance part="DEKODER_POWER" gate="-1" x="210.82" y="139.7" rot="R270"/>
<instance part="DEKODER_POWER" gate="-2" x="205.74" y="139.7" rot="R270"/>
<instance part="FREE" gate="-1" x="226.06" y="139.7" rot="R270"/>
<instance part="FREE" gate="-2" x="220.98" y="139.7" rot="R270"/>
<instance part="D1" gate="G$1" x="154.94" y="139.7" rot="R90"/>
<instance part="R3" gate="R" x="162.56" y="119.38" rot="R90"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="R1" gate="R" pin="1"/>
<wire x1="86.36" y1="38.1" x2="93.98" y2="38.1" width="0.1524" layer="91"/>
<pinref part="DZ1" gate="DZ" pin="A"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="T1" gate="T" pin="B"/>
<pinref part="DZ1" gate="DZ" pin="K"/>
<wire x1="71.12" y1="38.1" x2="78.74" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+12V" class="0">
<segment>
<pinref part="T1" gate="T" pin="E"/>
<wire x1="63.5" y1="43.18" x2="63.5" y2="50.8" width="0.1524" layer="91"/>
<wire x1="63.5" y1="50.8" x2="109.22" y2="50.8" width="0.1524" layer="91"/>
<junction x="63.5" y="50.8"/>
<pinref part="NAP2" gate="+12" pin="+12V"/>
<wire x1="50.8" y1="50.8" x2="63.5" y2="50.8" width="0.1524" layer="91"/>
<wire x1="50.8" y1="50.8" x2="50.8" y2="20.32" width="0.1524" layer="91"/>
<pinref part="TLACITKO" gate="-1" pin="KL"/>
<wire x1="50.8" y1="20.32" x2="48.26" y2="20.32" width="0.1524" layer="91"/>
<pinref part="SWITCH_PRIMARY" gate="-1" pin="KL"/>
<wire x1="45.72" y1="58.42" x2="45.72" y2="50.8" width="0.1524" layer="91"/>
<wire x1="45.72" y1="50.8" x2="50.8" y2="50.8" width="0.1524" layer="91"/>
<junction x="50.8" y="50.8"/>
</segment>
<segment>
<pinref part="NAP1" gate="+12" pin="+12V"/>
<wire x1="25.4" y1="127" x2="35.56" y2="127" width="0.1524" layer="91"/>
<pinref part="C1" gate="C" pin="C_EL+"/>
<wire x1="35.56" y1="127" x2="35.56" y2="121.92" width="0.1524" layer="91"/>
<junction x="35.56" y="127"/>
<pinref part="IC1" gate="A1" pin="VI"/>
<pinref part="C2" gate="C" pin="2"/>
<wire x1="35.56" y1="127" x2="63.5" y2="127" width="0.1524" layer="91"/>
<wire x1="63.5" y1="127" x2="93.98" y2="127" width="0.1524" layer="91"/>
<wire x1="93.98" y1="127" x2="106.68" y2="127" width="0.1524" layer="91"/>
<wire x1="106.68" y1="127" x2="109.22" y2="127" width="0.1524" layer="91"/>
<wire x1="106.68" y1="127" x2="106.68" y2="121.92" width="0.1524" layer="91"/>
<junction x="106.68" y="127"/>
<pinref part="SWITCH_MOTOR" gate="-2" pin="KL"/>
<wire x1="63.5" y1="134.62" x2="63.5" y2="127" width="0.1524" layer="91"/>
<junction x="63.5" y="127"/>
<pinref part="SWITCH-SICK" gate="-2" pin="KL"/>
<wire x1="93.98" y1="134.62" x2="93.98" y2="127" width="0.1524" layer="91"/>
<junction x="93.98" y="127"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="IRF3205" gate="G$1" pin="D"/>
<wire x1="106.68" y1="33.02" x2="106.68" y2="38.1" width="0.1524" layer="91"/>
<pinref part="GND2" gate="ZEM" pin="GND"/>
<wire x1="106.68" y1="38.1" x2="106.68" y2="43.18" width="0.1524" layer="91"/>
<wire x1="106.68" y1="43.18" x2="111.76" y2="43.18" width="0.1524" layer="91"/>
<pinref part="R1" gate="R" pin="2"/>
<wire x1="104.14" y1="38.1" x2="106.68" y2="38.1" width="0.1524" layer="91"/>
<junction x="106.68" y="38.1"/>
</segment>
<segment>
<pinref part="GND1" gate="ZEM" pin="GND"/>
<wire x1="25.4" y1="111.76" x2="35.56" y2="111.76" width="0.1524" layer="91"/>
<pinref part="C1" gate="C" pin="C_EL-"/>
<wire x1="35.56" y1="111.76" x2="35.56" y2="114.3" width="0.1524" layer="91"/>
<junction x="35.56" y="111.76"/>
<pinref part="IC1" gate="A1" pin="GND"/>
<wire x1="106.68" y1="111.76" x2="76.2" y2="111.76" width="0.1524" layer="91"/>
<wire x1="76.2" y1="111.76" x2="45.72" y2="111.76" width="0.1524" layer="91"/>
<wire x1="45.72" y1="111.76" x2="35.56" y2="111.76" width="0.1524" layer="91"/>
<wire x1="106.68" y1="111.76" x2="119.38" y2="111.76" width="0.1524" layer="91"/>
<wire x1="119.38" y1="111.76" x2="119.38" y2="119.38" width="0.1524" layer="91"/>
<pinref part="C2" gate="C" pin="1"/>
<wire x1="106.68" y1="114.3" x2="106.68" y2="111.76" width="0.1524" layer="91"/>
<junction x="106.68" y="111.76"/>
<wire x1="119.38" y1="111.76" x2="134.62" y2="111.76" width="0.1524" layer="91"/>
<junction x="119.38" y="111.76"/>
<pinref part="C3" gate="C" pin="1"/>
<wire x1="134.62" y1="111.76" x2="134.62" y2="114.3" width="0.1524" layer="91"/>
<pinref part="RASP_POWER" gate="-1" pin="KL"/>
<wire x1="180.34" y1="134.62" x2="180.34" y2="111.76" width="0.1524" layer="91"/>
<wire x1="180.34" y1="111.76" x2="162.56" y2="111.76" width="0.1524" layer="91"/>
<junction x="134.62" y="111.76"/>
<pinref part="MD22_POWER" gate="-1" pin="KL"/>
<wire x1="162.56" y1="111.76" x2="134.62" y2="111.76" width="0.1524" layer="91"/>
<wire x1="195.58" y1="134.62" x2="195.58" y2="111.76" width="0.1524" layer="91"/>
<wire x1="195.58" y1="111.76" x2="180.34" y2="111.76" width="0.1524" layer="91"/>
<junction x="180.34" y="111.76"/>
<pinref part="DEKODER_POWER" gate="-1" pin="KL"/>
<wire x1="210.82" y1="134.62" x2="210.82" y2="111.76" width="0.1524" layer="91"/>
<wire x1="210.82" y1="111.76" x2="195.58" y2="111.76" width="0.1524" layer="91"/>
<junction x="195.58" y="111.76"/>
<pinref part="FREE" gate="-1" pin="KL"/>
<wire x1="226.06" y1="134.62" x2="226.06" y2="111.76" width="0.1524" layer="91"/>
<wire x1="226.06" y1="111.76" x2="210.82" y2="111.76" width="0.1524" layer="91"/>
<junction x="210.82" y="111.76"/>
<pinref part="R3" gate="R" pin="1"/>
<wire x1="162.56" y1="114.3" x2="162.56" y2="111.76" width="0.1524" layer="91"/>
<junction x="162.56" y="111.76"/>
<pinref part="MOTOR_POWER" gate="-1" pin="KL"/>
<wire x1="45.72" y1="134.62" x2="45.72" y2="111.76" width="0.1524" layer="91"/>
<junction x="45.72" y="111.76"/>
<pinref part="SICK_POWER" gate="-1" pin="KL"/>
<wire x1="76.2" y1="134.62" x2="76.2" y2="111.76" width="0.1524" layer="91"/>
<junction x="76.2" y="111.76"/>
</segment>
</net>
<net name="GND_BATERIE" class="0">
<segment>
<pinref part="R2" gate="R" pin="1"/>
<wire x1="63.5" y1="12.7" x2="63.5" y2="10.16" width="0.1524" layer="91"/>
<wire x1="63.5" y1="10.16" x2="20.32" y2="10.16" width="0.1524" layer="91"/>
<wire x1="63.5" y1="10.16" x2="106.68" y2="10.16" width="0.1524" layer="91"/>
<junction x="63.5" y="10.16"/>
<pinref part="IRF3205" gate="G$1" pin="S"/>
<wire x1="106.68" y1="10.16" x2="106.68" y2="22.86" width="0.1524" layer="91"/>
<pinref part="BAT" gate="-1" pin="KL"/>
<wire x1="17.78" y1="25.4" x2="20.32" y2="25.4" width="0.1524" layer="91"/>
<wire x1="20.32" y1="25.4" x2="20.32" y2="10.16" width="0.1524" layer="91"/>
<pinref part="BAT" gate="-3" pin="KL"/>
<wire x1="17.78" y1="35.56" x2="20.32" y2="35.56" width="0.1524" layer="91"/>
<wire x1="20.32" y1="35.56" x2="20.32" y2="25.4" width="0.1524" layer="91"/>
<junction x="20.32" y="25.4"/>
<pinref part="CHARGE" gate="-1" pin="KL"/>
<wire x1="30.48" y1="25.4" x2="20.32" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="TLACITKO" gate="-2" pin="KL"/>
<pinref part="T1" gate="T" pin="C"/>
<wire x1="63.5" y1="33.02" x2="63.5" y2="25.4" width="0.1524" layer="91"/>
<pinref part="IRF3205" gate="G$1" pin="G"/>
<wire x1="63.5" y1="25.4" x2="101.6" y2="25.4" width="0.1524" layer="91"/>
<pinref part="R2" gate="R" pin="2"/>
<wire x1="63.5" y1="25.4" x2="63.5" y2="22.86" width="0.1524" layer="91"/>
<junction x="63.5" y="25.4"/>
<wire x1="48.26" y1="15.24" x2="55.88" y2="15.24" width="0.1524" layer="91"/>
<wire x1="55.88" y1="15.24" x2="55.88" y2="25.4" width="0.1524" layer="91"/>
<wire x1="55.88" y1="25.4" x2="63.5" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="POJ1" gate="POJ" pin="1"/>
<wire x1="27.94" y1="50.8" x2="22.86" y2="50.8" width="0.1524" layer="91"/>
<pinref part="BAT" gate="-2" pin="KL"/>
<wire x1="17.78" y1="30.48" x2="22.86" y2="30.48" width="0.1524" layer="91"/>
<pinref part="BAT" gate="-4" pin="KL"/>
<wire x1="22.86" y1="30.48" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<wire x1="22.86" y1="40.64" x2="17.78" y2="40.64" width="0.1524" layer="91"/>
<wire x1="22.86" y1="50.8" x2="22.86" y2="40.64" width="0.1524" layer="91"/>
<junction x="22.86" y="40.64"/>
<pinref part="CHARGE" gate="-2" pin="KL"/>
<wire x1="30.48" y1="30.48" x2="22.86" y2="30.48" width="0.1524" layer="91"/>
<junction x="22.86" y="30.48"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="POJ1" gate="POJ" pin="2"/>
<wire x1="38.1" y1="50.8" x2="40.64" y2="50.8" width="0.1524" layer="91"/>
<pinref part="SWITCH_PRIMARY" gate="-2" pin="KL"/>
<wire x1="40.64" y1="50.8" x2="40.64" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="IC1" gate="A1" pin="VO"/>
<wire x1="129.54" y1="127" x2="134.62" y2="127" width="0.1524" layer="91"/>
<pinref part="C3" gate="C" pin="2"/>
<wire x1="134.62" y1="127" x2="134.62" y2="121.92" width="0.1524" layer="91"/>
<wire x1="134.62" y1="127" x2="149.86" y2="127" width="0.1524" layer="91"/>
<junction x="134.62" y="127"/>
<pinref part="RASP_POWER" gate="-2" pin="KL"/>
<wire x1="149.86" y1="127" x2="175.26" y2="127" width="0.1524" layer="91"/>
<wire x1="175.26" y1="127" x2="175.26" y2="134.62" width="0.1524" layer="91"/>
<wire x1="175.26" y1="127" x2="190.5" y2="127" width="0.1524" layer="91"/>
<junction x="175.26" y="127"/>
<pinref part="MD22_POWER" gate="-2" pin="KL"/>
<wire x1="190.5" y1="127" x2="190.5" y2="134.62" width="0.1524" layer="91"/>
<wire x1="190.5" y1="127" x2="205.74" y2="127" width="0.1524" layer="91"/>
<junction x="190.5" y="127"/>
<pinref part="DEKODER_POWER" gate="-2" pin="KL"/>
<wire x1="205.74" y1="127" x2="205.74" y2="134.62" width="0.1524" layer="91"/>
<wire x1="205.74" y1="127" x2="220.98" y2="127" width="0.1524" layer="91"/>
<junction x="205.74" y="127"/>
<pinref part="FREE" gate="-2" pin="KL"/>
<wire x1="220.98" y1="127" x2="220.98" y2="134.62" width="0.1524" layer="91"/>
<pinref part="D1" gate="G$1" pin="A"/>
<wire x1="152.4" y1="139.7" x2="149.86" y2="139.7" width="0.1524" layer="91"/>
<wire x1="149.86" y1="139.7" x2="149.86" y2="127" width="0.1524" layer="91"/>
<junction x="149.86" y="127"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="D1" gate="G$1" pin="C"/>
<pinref part="R3" gate="R" pin="2"/>
<wire x1="160.02" y1="139.7" x2="162.56" y2="139.7" width="0.1524" layer="91"/>
<wire x1="162.56" y1="139.7" x2="162.56" y2="124.46" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="MOTOR_POWER" gate="-2" pin="KL"/>
<wire x1="50.8" y1="134.62" x2="50.8" y2="132.08" width="0.1524" layer="91"/>
<wire x1="50.8" y1="132.08" x2="58.42" y2="132.08" width="0.1524" layer="91"/>
<pinref part="SWITCH_MOTOR" gate="-1" pin="KL"/>
<wire x1="58.42" y1="132.08" x2="58.42" y2="134.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="SICK_POWER" gate="-2" pin="KL"/>
<wire x1="81.28" y1="134.62" x2="81.28" y2="132.08" width="0.1524" layer="91"/>
<wire x1="81.28" y1="132.08" x2="88.9" y2="132.08" width="0.1524" layer="91"/>
<pinref part="SWITCH-SICK" gate="-1" pin="KL"/>
<wire x1="88.9" y1="132.08" x2="88.9" y2="134.62" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
