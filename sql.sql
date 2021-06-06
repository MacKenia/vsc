//使用“DELIMITER &&”将 SQL 语句的结束符号变成&& 
DELIMITER &&
CREATE	PROCEDURE	Pfood_price_count (IN price_info1 FLOAT,IN price_info2 FLOAT, OUT count INT )
READS SQL DATA
 
BEGIN
// 定 义 变 量 temp
DECLARE temp FLOAT;
//定义游标match_price
DECLARE match_price CURSOR FOR SELECT price FROM food;
//定义条件处理。如果没有遇到关闭游标，旧退出存储过程
DECLARE EXIT HANDLER FOR NOT FOUND CLOSE match_price;
//为临时变量sum 赋值
SET @sum=0;
//用 SELECT … INTO 语句来为输出变量 count 赋值
SELECT	COUNT(*)	INTO	count	FROM	food WHERE	price>price_info1 AND price<price_info2;
//打开游标
OPEN match_price;
//执行循环
REPEAT
//使用游标match_price
FETCH match_price INTO temp;
//执行条件语句
IF temp>price_info1 AND temp<price_info2 THEN SET @sum=@sum+temp;
END IF;
//结束循环
UNTIL 0 END REPEAT;
//关闭游标
CLOSE match_price; END &&
//将 SQL 语句的结束符号变成“;”
DELIMITER ;
