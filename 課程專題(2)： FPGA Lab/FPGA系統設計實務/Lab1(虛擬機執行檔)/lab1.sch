<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="A" />
        <signal name="B" />
        <signal name="C" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="Sum" />
        <signal name="Cout" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Output" name="Sum" />
        <port polarity="Output" name="Cout" />
        <blockdef name="xor3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="208" y1="-128" y2="-128" x1="256" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <arc ex="64" ey="-176" sx="64" sy="-80" r="56" cx="32" cy="-128" />
            <arc ex="128" ey="-176" sx="208" sy="-128" r="88" cx="132" cy="-88" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="64" y1="-80" y2="-80" x1="128" />
            <line x2="64" y1="-176" y2="-176" x1="128" />
            <arc ex="208" ey="-128" sx="128" sy="-80" r="88" cx="132" cy="-168" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
        </blockdef>
        <block symbolname="xor3" name="XLXI_1">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="A" name="I2" />
            <blockpin signalname="Sum" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_5">
            <blockpin signalname="XLXN_7" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="XLXN_6" name="I2" />
            <blockpin signalname="Cout" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="A">
            <wire x2="288" y1="352" y2="432" x1="288" />
            <wire x2="800" y1="432" y2="432" x1="288" />
            <wire x2="288" y1="432" y2="800" x1="288" />
            <wire x2="288" y1="800" y2="960" x1="288" />
            <wire x2="288" y1="960" y2="1600" x1="288" />
            <wire x2="560" y1="960" y2="960" x1="288" />
            <wire x2="560" y1="800" y2="800" x1="288" />
        </branch>
        <iomarker fontsize="28" x="288" y="352" name="A" orien="R270" />
        <branch name="B">
            <wire x2="368" y1="352" y2="496" x1="368" />
            <wire x2="800" y1="496" y2="496" x1="368" />
            <wire x2="368" y1="496" y2="864" x1="368" />
            <wire x2="368" y1="864" y2="1120" x1="368" />
            <wire x2="368" y1="1120" y2="1600" x1="368" />
            <wire x2="560" y1="1120" y2="1120" x1="368" />
            <wire x2="560" y1="864" y2="864" x1="368" />
        </branch>
        <iomarker fontsize="28" x="368" y="352" name="B" orien="R270" />
        <branch name="C">
            <wire x2="448" y1="352" y2="560" x1="448" />
            <wire x2="800" y1="560" y2="560" x1="448" />
            <wire x2="448" y1="560" y2="1024" x1="448" />
            <wire x2="560" y1="1024" y2="1024" x1="448" />
            <wire x2="448" y1="1024" y2="1184" x1="448" />
            <wire x2="448" y1="1184" y2="1600" x1="448" />
            <wire x2="560" y1="1184" y2="1184" x1="448" />
        </branch>
        <iomarker fontsize="28" x="448" y="352" name="C" orien="R270" />
        <instance x="800" y="624" name="XLXI_1" orien="R0" />
        <instance x="560" y="1248" name="XLXI_4" orien="R0" />
        <instance x="560" y="1088" name="XLXI_3" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="848" y1="992" y2="992" x1="816" />
        </branch>
        <instance x="848" y="1120" name="XLXI_5" orien="R0" />
        <instance x="560" y="928" name="XLXI_2" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="848" y1="832" y2="832" x1="816" />
            <wire x2="848" y1="832" y2="928" x1="848" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="848" y1="1152" y2="1152" x1="816" />
            <wire x2="848" y1="1056" y2="1152" x1="848" />
        </branch>
        <branch name="Sum">
            <wire x2="1088" y1="496" y2="496" x1="1056" />
        </branch>
        <iomarker fontsize="28" x="1088" y="496" name="Sum" orien="R0" />
        <branch name="Cout">
            <wire x2="1136" y1="992" y2="992" x1="1104" />
        </branch>
        <iomarker fontsize="28" x="1136" y="992" name="Cout" orien="R0" />
    </sheet>
</drawing>