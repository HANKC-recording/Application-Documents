LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;

-- =================================================================
-- Top Module：4位元加減法器
-- =================================================================
entity FullAdder4 is
port (
    A, B: in std_logic_vector(3 downto 0); -- 4位元運算元
    Ci: in std_logic;                      -- 初始進位/借位輸入
    Sub: in std_logic;                     -- 控制訊號(0為加法；1為減法)
    S: out std_logic_vector(3 downto 0);   -- 4位元運算結果
    Co: out std_logic);                    -- 最終進位/借位輸出
end FullAdder4;

-- 4位元加減法器的結構
architecture Structure of FullAdder4 is
-- 宣告1位元加減法器以便呼叫
component FullAdder
    port (  A, B, Cin, Sub: in std_logic;
        Cout, Sum: out std_logic );
end component;

-- 宣告內部訊號C，用來作為各個1位元加減法器之間的進位/借位傳遞線(C1, C2, C3)
signal C: std_logic_vector(3 downto 1);
begin
    -- 實體化四個 1 位元加減法器，並使用 port map 進行接線 (對應圖一的方塊圖)
    -- 共用Sub訊號
    FA0: FullAdder port map(A(0), B(0), Ci, Sub, C(1), S(0));   -- 第 0 位元 (LSB 最低位)
    FA1: FullAdder port map(A(1), B(1), C(1), Sub, C(2), S(1)); -- 第 1 位元
    FA2: FullAdder port map(A(2), B(2), C(2), Sub, C(3), S(2)); -- 第 2 位元
    FA3: FullAdder port map(A(3), B(3), C(3), Sub, Co, S(3));   -- 第 3 位元 (MSB 最高位)
end Structure;


-- =================================================================
-- Bottom Component：1位元加減法器
-- =================================================================
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;

-- 宣告1位元加減法器
entity FullAdder is
  port (
    A, B, Cin, Sub: in std_logic; -- 1 位元輸入與控制訊號
    Sum, Cout: out std_logic);    -- 1 位元輸出
end FullAdder;

architecture WithSelect of FullAdder is

 -- 宣告4位元的內部訊號sel，用來將四個輸入打包，方便用於查表索引
 signal sel : std_logic_vector(3 downto 0);

begin

  -- 將四個輸入串接成選擇向量
  sel <= A & B & Cin & Sub;

  -- ===============================================================
  -- 列出所有Sum會輸出'1'的條件，其餘情況輸出 '0'
  -- ===============================================================
  with sel select
    Sum <= '1' when "0010",   -- A=0 B=0 Cin=1 Sub=0 (加法：0+0+1 = 和1)
           '1' when "0011",   -- A=0 B=0 Cin=1 Sub=1 (減法：0-0-1 = 差1，需借位)
           '1' when "0100",   -- A=0 B=1 Cin=0 Sub=0 (加法：0+1+0 = 和1)
           '1' when "0101",   -- A=0 B=1 Cin=0 Sub=1 (減法：0-1-0 = 差1，需借位)
           '1' when "1000",   -- A=1 B=0 Cin=0 Sub=0 (加法：1+0+0 = 和1)
           '1' when "1001",   -- A=1 B=0 Cin=0 Sub=1 (減法：1-0-0 = 差1)
           '1' when "1110",   -- A=1 B=1 Cin=1 Sub=0 (加法：1+1+1 = 和1，有進位)
           '1' when "1111",   -- A=1 B=1 Cin=1 Sub=1 (減法：1-1-1 = 差1，需借位)
           '0' when others;   -- 涵蓋剩下的 8 種組合

  -- ===============================================================
  -- 列出所有Cout會輸出'1'的條件
  -- ===============================================================
  with sel select
    Cout <= '1' when "0011",  -- A=0 B=0 Cin=1 Sub=1 (減法：0 不夠減 1，產生借位)
            '1' when "0101",  -- A=0 B=1 Cin=0 Sub=1 (減法：0 不夠減 1，產生借位)
            '1' when "0110",  -- A=0 B=1 Cin=1 Sub=0 (加法：0+1+1 = 2，產生進位)
            '1' when "0111",  -- A=0 B=1 Cin=1 Sub=1 (減法：0 不夠減 (1+1)，產生借位)
            '1' when "1010",  -- A=1 B=0 Cin=1 Sub=0 (加法：1+0+1 = 2，產生進位)
            '1' when "1100",  -- A=1 B=1 Cin=0 Sub=0 (加法：1+1+0 = 2，產生進位)
            '1' when "1110",  -- A=1 B=1 Cin=1 Sub=0 (加法：1+1+1 = 3，產生進位)
            '1' when "1111",  -- A=1 B=1 Cin=1 Sub=1 (減法：1 不夠減 (1+1)，產生借位)
            '0' when others;  -- 涵蓋剩下的 8 種組合

end WithSelect;