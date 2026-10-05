<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="Sum0" />
        <signal name="Sum1" />
        <signal name="Sum2" />
        <signal name="Sum3" />
        <signal name="A0" />
        <signal name="A1" />
        <signal name="A2" />
        <signal name="A3" />
        <signal name="B0" />
        <signal name="B1" />
        <signal name="B2" />
        <signal name="B3" />
        <signal name="Cin" />
        <signal name="Cout" />
        <port polarity="Output" name="Sum0" />
        <port polarity="Output" name="Sum1" />
        <port polarity="Output" name="Sum2" />
        <port polarity="Output" name="Sum3" />
        <port polarity="Input" name="A0" />
        <port polarity="Input" name="A1" />
        <port polarity="Input" name="A2" />
        <port polarity="Input" name="A3" />
        <port polarity="Input" name="B0" />
        <port polarity="Input" name="B1" />
        <port polarity="Input" name="B2" />
        <port polarity="Input" name="B3" />
        <port polarity="Input" name="Cin" />
        <port polarity="Output" name="Cout" />
        <blockdef name="full_adder_1bits">
            <timestamp>2026-3-8T15:37:26</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="full_adder_1bits" name="XLXI_1">
            <blockpin signalname="A3" name="A" />
            <blockpin signalname="B3" name="B" />
            <blockpin signalname="XLXN_3" name="Cin" />
            <blockpin signalname="Cout" name="Cout" />
            <blockpin signalname="Sum3" name="Sum" />
        </block>
        <block symbolname="full_adder_1bits" name="XLXI_2">
            <blockpin signalname="A2" name="A" />
            <blockpin signalname="B2" name="B" />
            <blockpin signalname="XLXN_2" name="Cin" />
            <blockpin signalname="XLXN_3" name="Cout" />
            <blockpin signalname="Sum2" name="Sum" />
        </block>
        <block symbolname="full_adder_1bits" name="XLXI_3">
            <blockpin signalname="A1" name="A" />
            <blockpin signalname="B1" name="B" />
            <blockpin signalname="XLXN_1" name="Cin" />
            <blockpin signalname="XLXN_2" name="Cout" />
            <blockpin signalname="Sum1" name="Sum" />
        </block>
        <block symbolname="full_adder_1bits" name="XLXI_4">
            <blockpin signalname="A0" name="A" />
            <blockpin signalname="B0" name="B" />
            <blockpin signalname="Cin" name="Cin" />
            <blockpin signalname="XLXN_1" name="Cout" />
            <blockpin signalname="Sum0" name="Sum" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="640" y="800" name="XLXI_1" orien="R90">
        </instance>
        <instance x="1120" y="800" name="XLXI_2" orien="R90">
        </instance>
        <instance x="1600" y="800" name="XLXI_3" orien="R90">
        </instance>
        <instance x="2080" y="800" name="XLXI_4" orien="R90">
        </instance>
        <branch name="XLXN_1">
            <wire x2="1760" y1="736" y2="800" x1="1760" />
            <wire x2="2000" y1="736" y2="736" x1="1760" />
            <wire x2="2000" y1="736" y2="1264" x1="2000" />
            <wire x2="2176" y1="1264" y2="1264" x1="2000" />
            <wire x2="2176" y1="1184" y2="1264" x1="2176" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1280" y1="736" y2="800" x1="1280" />
            <wire x2="1520" y1="736" y2="736" x1="1280" />
            <wire x2="1520" y1="736" y2="1264" x1="1520" />
            <wire x2="1696" y1="1264" y2="1264" x1="1520" />
            <wire x2="1696" y1="1184" y2="1264" x1="1696" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="800" y1="736" y2="800" x1="800" />
            <wire x2="1040" y1="736" y2="736" x1="800" />
            <wire x2="1040" y1="736" y2="1264" x1="1040" />
            <wire x2="1216" y1="1264" y2="1264" x1="1040" />
            <wire x2="1216" y1="1184" y2="1264" x1="1216" />
        </branch>
        <branch name="Sum0">
            <wire x2="2240" y1="1184" y2="1216" x1="2240" />
        </branch>
        <iomarker fontsize="28" x="2240" y="1216" name="Sum0" orien="R90" />
        <branch name="Sum1">
            <wire x2="1760" y1="1184" y2="1216" x1="1760" />
        </branch>
        <iomarker fontsize="28" x="1760" y="1216" name="Sum1" orien="R90" />
        <branch name="Sum2">
            <wire x2="1280" y1="1184" y2="1216" x1="1280" />
        </branch>
        <iomarker fontsize="28" x="1280" y="1216" name="Sum2" orien="R90" />
        <branch name="Sum3">
            <wire x2="800" y1="1184" y2="1216" x1="800" />
        </branch>
        <iomarker fontsize="28" x="800" y="1216" name="Sum3" orien="R90" />
        <branch name="A0">
            <wire x2="2112" y1="768" y2="800" x1="2112" />
        </branch>
        <iomarker fontsize="28" x="2112" y="768" name="A0" orien="R270" />
        <branch name="A1">
            <wire x2="1632" y1="768" y2="800" x1="1632" />
        </branch>
        <iomarker fontsize="28" x="1632" y="768" name="A1" orien="R270" />
        <branch name="A2">
            <wire x2="1152" y1="768" y2="800" x1="1152" />
        </branch>
        <iomarker fontsize="28" x="1152" y="768" name="A2" orien="R270" />
        <branch name="A3">
            <wire x2="672" y1="768" y2="800" x1="672" />
        </branch>
        <iomarker fontsize="28" x="672" y="768" name="A3" orien="R270" />
        <branch name="B0">
            <wire x2="2176" y1="768" y2="800" x1="2176" />
        </branch>
        <iomarker fontsize="28" x="2176" y="768" name="B0" orien="R270" />
        <branch name="B1">
            <wire x2="1696" y1="768" y2="800" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1696" y="768" name="B1" orien="R270" />
        <branch name="B2">
            <wire x2="1216" y1="768" y2="800" x1="1216" />
        </branch>
        <iomarker fontsize="28" x="1216" y="768" name="B2" orien="R270" />
        <branch name="B3">
            <wire x2="736" y1="768" y2="800" x1="736" />
        </branch>
        <iomarker fontsize="28" x="736" y="768" name="B3" orien="R270" />
        <branch name="Cin">
            <wire x2="2240" y1="768" y2="784" x1="2240" />
            <wire x2="2240" y1="784" y2="800" x1="2240" />
        </branch>
        <branch name="Cout">
            <wire x2="736" y1="1184" y2="1216" x1="736" />
        </branch>
        <iomarker fontsize="28" x="736" y="1216" name="Cout" orien="R90" />
        <iomarker fontsize="28" x="2240" y="768" name="Cin" orien="R270" />
    </sheet>
</drawing>