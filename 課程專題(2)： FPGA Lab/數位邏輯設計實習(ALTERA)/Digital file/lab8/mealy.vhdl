library ieee;
use ieee.std_logic_1164.all;

entity mealy is	
	port (
		-- Input ports
		clk, x : in  std_logic;
		-- Output ports		
		y      : out std_logic;  -- 修正：補上分號
		z      : out std_logic_vector(2 downto 0)
	);
end mealy;

architecture state_graph of mealy is
    -- 必須宣告一個內部信號來存儲狀態，因為 out 腳位不能被讀取
    signal z_internal : std_logic_vector(2 downto 0) := "000";
begin
    -- 【新增】：將內部狀態信號即時輸出給腳位 z
    z <= z_internal;

    -- 以下的邏輯判斷，全部改用內部信號 z_internal
    y <= '1' when (z_internal = "010" and x = '1') or (z_internal = "100" and x = '1') else '0';

    process(clk) is
    begin
        if(rising_edge(clk)) then
            if(z_internal = "000") then         -- 當前狀態 S0
                if(x = '0') then 
                    z_internal <= "001";        -- x=0 跳至 S1
                else 
                    z_internal <= "011";        -- x=1 跳至 S3
                end if;
                
            elsif(z_internal = "001") then      -- 當前狀態 S1
                if(x = '0') then 
                    z_internal <= "010";        -- x=0 跳至 S2
                else 
                    z_internal <= "011";        -- x=1 跳至 S3
                end if;
                
            elsif(z_internal = "010") then      -- 當前狀態 S2
                if(x = '0') then 
                    z_internal <= "001";        -- x=0 跳至 S1
                else 
                    z_internal <= "011";        -- x=1 跳至 S3
                end if;
                
            elsif(z_internal = "011") then      -- 當前狀態 S3
                if(x = '0') then 
                    z_internal <= "100";        -- x=0 跳至 S4
                else 
                    z_internal <= "000";        -- x=1 跳至 S0
                end if;
                
            elsif(z_internal = "100") then      -- 當前狀態 S4
                if(x = '0') then 
                    z_internal <= "011";        -- x=0 跳至 S3
                else 
                    z_internal <= "000";        -- x=1 跳至 S0
                end if;
                
            else
                z_internal <= "000";            -- 預防未知狀態，拉回 S0
            end if;
        end if;
    end process;
end state_graph;