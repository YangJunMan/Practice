use 양준혁_account_book;
delimiter //

/* 
2022년 데이터베이스과목 개인 프로젝트

●가계부
은행 : 계좌개설 및 카드 발급, 회원정보 저장
사용자 : 현금자산, 계좌의 수입 및 지출 이용 가능e
가계부 : 모든 수입, 지출내역 내역 및 메모 확인 가능

가계부의 수입,지출 기능(#1-1~17) : 계좌 현금 인출 및 계좌이체, 체크카드(선불) 및 신용카드(후불) 사용 가능
서비스(#2-1~10)
함수(#3-1~4)
추가조건(#4-1~15)

모든 수입, 지출은 금액이 부족할 시 발동하지 않습니다
없는 아이디, 유형 등을 입력할시에는 데이터베이스에 정보가 저장되지 않도록 작성

*/

/*	
	지출기능		
	
	#1-1,2,3,5,6,7,8 
	#3-1,4
	#4-10,11,12,13 
*/
create procedure spend(
	pro_customer_id VARCHAR(45),
    pro_place_spend VARCHAR(45),
	pro_item_spend VARCHAR(45), 
	pro_amount_spend INT,
	pro_date_spend DATETIME, 
    pro_type_transaction VARCHAR(45),
    pro_smalltype_transaction VARCHAR(45)
)
PROC_BODY : BEGIN

DECLARE temp_amount_cash INT;
DECLARE temp_amount INT;
DECLARE temp_transaction_num INT;
DECLARE temp_id_check_card INT;
DECLARE temp_id_credit_card INT;
DECLARE temp_id_expect INT;
DECLARE temp_date_spend DATE;

SELECT count(*)+1
INTO temp_transaction_num
FROM transaction;
SELECT count(*)+1
INTO temp_id_expect
FROM expect;

if(pro_date_spend is NULL) THEN
SET pro_date_spend = NOW();	-- 입금날짜 미입력시 현재 시각으로 생성
END IF;


iF(pro_smalltype_transaction is NULL)THEN	-- 소분류 미작성시 대분류 항목으로 자동 입력
	set pro_smalltype_transaction=pro_type_transaction;
END IF;

SELECT amount_cash into temp_amount_cash FROM cash WHERE id_customer=pro_customer_id;
SELECT balance into temp_amount FROM account WHERE id_customer=pro_customer_id;

	IF(pro_item_spend='현금') THEN -- 현금, 체크카드 등 지출 구현
        if(temp_amount_cash <pro_amount_spend) THEN
            INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,spending_transaction,income_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction) values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,'실패_현금지출',0,0,temp_amount_cash,temp_amount,'실패_잔액부족',concat(pro_amount_spend,'원 결제 불가'));
			LEAVE PROC_BODY;
        ELSE
			UPDATE cash SET cash.amount_cash=(cash.amount_cash-pro_amount_spend) WHERE cash.id_customer=pro_customer_id;
            SELECT amount_cash into temp_amount_cash FROM cash WHERE id_customer=pro_customer_id;
			INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,spending_transaction,income_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction) values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,'현금지출',pro_amount_spend,0,temp_amount_cash,temp_amount,pro_type_transaction,pro_smalltype_transaction);
		END IF;
    ELSEIF (pro_item_spend='체크카드') THEN
		SELECT id_check_card into temp_id_check_card from check_card WHERE check_card.id_account=(SELECT id_account from account WHERE pro_customer_id=account.id_customer);
        if(temp_amount<pro_amount_spend)THEN
			INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction) 
            values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,'실패_카드지출',0,0,temp_amount_cash,temp_amount,'실패_잔액부족',concat(pro_amount_spend,'원 결제 불가'));
			LEAVE PROC_BODY;
        ELSE
			UPDATE account SET account.balance=(account.balance-pro_amount_spend) WHERE account.id_customer=pro_customer_id;
            SELECT balance into temp_amount FROM account WHERE id_customer=pro_customer_id;
			INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction)  
            values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,concat('체크카드_승인_',temp_id_check_card),0,pro_amount_spend,temp_amount_cash,temp_amount,pro_type_transaction,pro_smalltype_transaction);
        END IF;
	ELSEIF(pro_item_spend='신용카드') THEN
		set temp_date_spend=pro_date_spend;
        
        SELECT id_credit_card into temp_id_credit_card from credit_card WHERE credit_card.id_account=(SELECT id_account from account WHERE pro_customer_id=account.id_customer);
		SELECT balance into temp_amount_cash FROM account WHERE id_customer=pro_customer_id;
		SELECT amount_cash into temp_amount FROM cash WHERE id_customer=pro_customer_id;
 
		insert into expect(id_expect,id_credit_card,date_expect_payment,amount_expect,date_approve_expect) values(temp_id_expect,temp_id_credit_card,DATE_ADD(temp_date_spend,INTERVAL 1 MONTH),pro_amount_spend,temp_date_spend);
        INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_account,balance_cash,type_transaction,smalltype_transaction) values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,concat('신용카드_승인_',temp_id_credit_card),0,pro_amount_spend,temp_amount_cash,temp_amount,pro_type_transaction,pro_smalltype_transaction);
    ELSEIF(pro_item_spend='출금')then
        if(temp_amount <pro_amount_spend) THEN
            INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction) values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,'실패_출금',0,0,temp_amount_cash,temp_amount,'실패_잔액부족',concat(pro_amount_spend,'원 출금 불가'));
            LEAVE PROC_BODY;
		ELSE
			UPDATE account SET account.balance=(account.balance-pro_amount_spend) WHERE account.id_customer=pro_customer_id;
			UPDATE cash SET cash.amount_cash=(cash.amount_cash+pro_amount_spend) WHERE cash.id_customer=pro_customer_id;
			SELECT balance into temp_amount FROM account WHERE id_customer=pro_customer_id;
			SELECT amount_cash into temp_amount_cash FROM cash WHERE id_customer=pro_customer_id;
			INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction) values(temp_transaction_num,pro_customer_id,pro_place_spend,pro_date_spend,'출금',0,pro_amount_spend,temp_amount_cash,temp_amount,pro_type_transaction,pro_smalltype_transaction);
		END IF;        
    END IF;
    
END//

/*
	수입기능 
	
	#1-4
*/
create procedure income(
	pro_customer_id VARCHAR(45),    
	pro_place_income VARCHAR(45),
	pro_item_income VARCHAR(45),-- 현금OR카드
    pro_amount_income INT, 		-- 금액
    pro_date_income DATETIME, 	-- 입금날짜
    pro_type_transaction VARCHAR(45), -- 수입항목
    pro_smalltype_transaction VARCHAR(45)
)
PROC_BODY : BEGIN 
DECLARE temp_amount_income INT;
DECLARE temp_amount INT;
DECLARE temp_transaction_num INT;
DECLARE temp_account_balance INT;
DECLARE temp_amount_cash INT;

SELECT count(*)+1
INTO temp_transaction_num
FROM transaction;

if(pro_date_income is NULL) THEN 
	SET pro_date_income = NOW();
END IF;
IF(pro_smalltype_transaction is NULL)THEN
	set pro_smalltype_transaction=pro_type_transaction;
END IF;

SELECT amount_cash into temp_amount_cash FROM cash WHERE id_customer=pro_customer_id;
SELECT balance into temp_amount_income FROM account WHERE id_customer=pro_customer_id;
		
	IF(pro_item_income='현금') THEN		-- 현금 수입
		UPDATE cash SET cash.amount_cash=(cash.amount_cash+pro_amount_income) WHERE cash.id_customer=pro_customer_id;
        SELECT amount_cash into temp_amount_income FROM cash WHERE id_customer=pro_customer_id;
        
        SELECT balance into temp_amount FROM account WHERE id_customer=pro_customer_id;
        INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,spending_transaction,item_transaction,balance_cash,balance_account,income_transaction,type_transaction,smalltype_transaction)
        values(temp_transaction_num,pro_customer_id,pro_place_income,pro_date_income,0,'현금수입',temp_amount_cash,temp_amount_income,pro_amount_income,pro_type_transaction,pro_smalltype_transaction);
	ELSEIF(pro_item_income='입금')THEN
		 if(temp_amount_cash<pro_amount_income)THEN		-- 입금할 현금이 부족하다면 실패
			INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction) 
            values(temp_transaction_num,pro_customer_id,'은행',pro_date_income,'실패',pro_amount_income,0,temp_amount_cash,temp_amount_income,'실패_현금부족',concat(pro_amount_income,'원 입금 불가'));
			LEAVE PROC_BODY;
		ELSE
			UPDATE cash SET cash.amount_cash=(cash.amount_cash-pro_amount_income) WHERE cash.id_customer=pro_customer_id;
            UPDATE account SET account.balance=(account.balance+pro_amount_income) WHERE account.id_customer=pro_customer_id;
            
            SELECT balance into temp_amount_income FROM account WHERE account.id_customer=pro_customer_id;
			SELECT amount_cash into temp_amount_cash FROM cash WHERE cash.id_customer=pro_customer_id;

			INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,income_transaction,spending_transaction,balance_account,balance_cash,type_transaction,smalltype_transaction)
			values(temp_transaction_num,pro_customer_id,'은행',pro_date_income,'입금',pro_amount_income,0,temp_amount_income,temp_amount_cash,pro_type_transaction,pro_smalltype_transaction);
        END IF;
	END IF;
END//

/*
	지출항목,목표생성
	
	#1-7,8
*/
create procedure spend_type_target(
pro_customer_id VARCHAR(45),
pro_type_spending VARCHAR(45),
pro_smalltype_spending VARCHAR(45),
pro_target_type_spending VARCHAR(45)
)
BEGIN
DECLARE temp_id_target_spending INT;
	SELECT count(*)+1
	INTO temp_id_target_spending
	FROM target_spending;
INSERT target_spending(id_target_spending,id_customer,type_spending,smalltype_spending,target_type_spending)values(temp_id_target_spending,pro_customer_id,pro_type_spending,pro_smalltype_spending,pro_target_type_spending);
END//
/*
	계좌이체

	#1-14
*/
create procedure transfer(
	pro_customer_id VARCHAR(45),
	pro_account_transfer INT, -- 입금할 계좌번호
    pro_amount_spend INT, -- 금액
    pro_date_spend DATETIME, -- 입금날짜
	pro_type_transaction VARCHAR(45), -- 메모 대분류
    pro_smalltype_transaction VARCHAR(45) -- 메모 소분류
)
PROC_BODY : BEGIN

	DECLARE temp_id_account INT;
    DECLARE temp_amount_cash INT;	
    DECLARE temp_transaction_num INT;
    DECLARE temp_transfer_id_customer VARCHAR(45);
    DECLARE temp_amount INT;
SELECT count(*)+1
INTO temp_transaction_num
FROM transaction;

SELECT account.id_customer into temp_transfer_id_customer FROM account WHERE account.id_account=pro_account_transfer; 

iF(pro_smalltype_transaction is NULL)THEN 
	set pro_smalltype_transaction=pro_type_transaction;
END IF;    
    
SELECT id_account into temp_id_account from account WHERE pro_customer_id=account.id_customer;
SELECT balance into temp_amount FROM account WHERE id_customer=pro_customer_id;
SELECT amount_cash into temp_amount_cash FROM cash WHERE id_customer=pro_customer_id;

if(temp_amount<pro_amount_spend) THEN -- 자산 부족시
	INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,spending_transaction,income_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction)
	values(temp_transaction_num,pro_customer_id,'은행',pro_date_spend,'실패_계좌이체',0,0,temp_amount_cash,temp_amount,'실패_잔액부족',concat(pro_amount_spend,'원 이체 불가'));
    LEAVE PROC_BODY;
ELSE
	UPDATE account set  account.balance=(account.balance-pro_amount_spend) WHERE id_account=temp_id_account;
    SELECT balance into temp_amount FROM account WHERE id_customer=pro_customer_id;
	INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,spending_transaction,income_transaction,balance_cash,balance_account,type_transaction,smalltype_transaction)
	values(temp_transaction_num,pro_customer_id,'은행',pro_date_spend,concat('계좌이체_',pro_account_transfer),pro_amount_spend,0,temp_amount_cash,temp_amount,pro_type_transaction,pro_smalltype_transaction);
	
    UPDATE account set  account.balance=(account.balance+pro_amount_spend) WHERE id_account=pro_account_transfer;
    
    SELECT balance into temp_amount_cash FROM account WHERE id_customer=temp_transfer_id_customer;
	SELECT amount_cash into temp_amount FROM cash WHERE id_customer=temp_transfer_id_customer;
    
    INSERT into transaction(id_transaction,id_customer,place_transaction,date_transaction,item_transaction,spending_transaction,income_transaction,balance_account,balance_cash,type_transaction,smalltype_transaction)
	values(temp_transaction_num,temp_transfer_id_customer,'은행',pro_date_spend,concat('계좌이체_',temp_id_account),0,pro_amount_spend,temp_amount_cash,temp_amount,pro_type_transaction,pro_smalltype_transaction);
END IF;
END//
/*
	지출이자계산
	
	#1-15,17
*/
create procedure update_fixed_spending( 
pro_account_id INT
)
BEGIN
DECLARE temp_amount_fixed_spending INT;
DECLARE temp_percent_fixed_spending INT;
DECLARE temp_sum_amount_expect INT;
DECLARE temp_credit_card INT;
SELECT percent_fixed_spending into temp_percent_fixed_spending from fixed_spending WHERE fixed_spending.id_account=pro_account_id;
SELECT id_credit_card into temp_credit_card from credit_card WHERE credit_card.id_account=pro_account_id;
SELECT sum(amount_expect) into temp_sum_amount_expect from expect WHERE expect.id_credit_card=temp_credit_card;
set temp_amount_fixed_spending=(temp_sum_amount_expect*temp_percent_fixed_spending/100);

update fixed_spending set amount_fixed_spending=(temp_amount_fixed_spending) WHERE fixed_spending.id_account=pro_account_id;

END//

/*
	수입이자계산 		
	#1-16				
	#3-2,3
*/

create procedure update_fixed_income( 
pro_account_id INT
)
BEGIN

DECLARE temp_amount_fixed_income INT;
DECLARE temp_account_balance INT;
DECLARE temp_percent_fixed_income INT;

SELECT balance into temp_account_balance from account WHERE account.id_account=pro_account_id;
SELECT percent_fixed_income into temp_percent_fixed_income from fixed_income WHERE fixed_income.id_account=pro_account_id;
set temp_amount_fixed_income=(temp_account_balance*temp_percent_fixed_income/100);
update fixed_income set amount_fixed_income=(temp_amount_fixed_income) WHERE fixed_income.id_account=pro_account_id;

END//

/*
	사용자등록

	#4-1
*/ 

create procedure create_customer(
	pro_customer_id VARCHAR(45),
	pro_customer_phone VARCHAR(45),
	pro_customer_name VARCHAR(45)
)

BEGIN
DECLARE temp_customer_id VARCHAR(45);
if(EXISTS(SELECT id_customer from customer WHERE customer.id_customer=pro_customer_id) =0) THEN
	INSERT INTO customer(id_customer,phone_customer,name_customer) values(pro_customer_id,pro_customer_phone,pro_customer_name);
END IF;
END//

/*
	계좌생성

	#4-2,5,6,7,8
*/ 
create procedure create_account(
pro_customer_id VARCHAR(45),
pro_bank_name VARCHAR(45),
pro_date_account DATE
)
BEGIN 
	DECLARE a_num int;
	DECLARE temp_bank VARCHAR(45);
    DECLARE temp_customer_name VARCHAR(45);
    SELECT bank.id_bank INTO temp_bank from bank WHERE bank.name_bank=pro_bank_name;
    SELECT customer.name_customer INTO temp_customer_name FROM customer WHERE pro_customer_id=customer.id_customer;
    if(EXISTS(SELECT id_customer from account WHERE account.id_customer=pro_customer_id) =0) THEN
		IF(pro_bank_name='국민은행') then
			SELECT (count(*)+1000) INTO a_num FROM account;
			INSERT INTO account(id_account,name_customer,name_bank,id_customer,id_bank,date_account,card_apply_status,checkcard_apply_status,balance) values(a_num,temp_customer_name,pro_bank_name,pro_customer_id,temp_bank,pro_date_account,0,0,0);
			INSERT fixed_spending(id_account,percent_fixed_spending,amount_fixed_spending) 
			values(a_num,3,0);
			INSERT fixed_income(id_account,percent_fixed_income,amount_fixed_income) 
			values(a_num,3,0);
		ELSEIF(pro_bank_name='신한은행') then
			SELECT (count(*)+2000) INTO a_num FROM account;
			INSERT INTO account(id_account,name_customer,name_bank,id_customer,id_bank,date_account,card_apply_status,checkcard_apply_status,balance) values(a_num,temp_customer_name,pro_bank_name,pro_customer_id,temp_bank,pro_date_account,0,0,0);
			INSERT fixed_spending(id_account,percent_fixed_spending,amount_fixed_spending) 
			values(a_num,4,0);
			INSERT fixed_income(id_account,percent_fixed_income,amount_fixed_income) 
			values(a_num,4,0);
		ELSEIF(pro_bank_name='농협은행') then
			SELECT (count(*)+3000) INTO a_num FROM account;
			INSERT INTO account(id_account,name_customer,name_bank,id_customer,id_bank,date_account,card_apply_status,checkcard_apply_status,balance) values(a_num,temp_customer_name,pro_bank_name,pro_customer_id,temp_bank,pro_date_account,0,0,0);
			INSERT fixed_spending(id_account,percent_fixed_spending,amount_fixed_spending) 
			values(a_num,5,0);
			INSERT fixed_income(id_account,percent_fixed_income,amount_fixed_income) 
			values(a_num,5,0);
		END IF;
    END IF;
END//
/*
	초기자본설정
	
	#4-3
*/ 
create procedure set_cash_amount(
	pro_customer_id VARCHAR(45),
    pro_amount_income INT
)
BEGIN
	insert into cash(cash.id_customer,amount_cash) values (pro_customer_id,pro_amount_income);
    
END//
/*
	신용카드생성
	#4-9
*/ 
create procedure create_check_card(

	pro_customer_id VARCHAR(45),
    pro_bank_name VARCHAR(45),
    pro_card_name VARCHAR(45)
)

/*	
	체크카드새성

	#4-9
*/
BEGIN 
	DECLARE card_num int;
    DECLARE temp_bank int;
    DECLARE temp_date_payment INT;
    DECLARE temp_min_payment INT;

set temp_bank=(SELECT bank.id_bank from bank WHERE bank.name_bank=pro_bank_name);

	SELECT count(*)+1
	INTO card_num
	FROM check_card;

	UPDATE account SET checkcard_apply_status=1 WHERE id_customer=pro_customer_id
    and account.id_bank=(temp_bank);
    INSERT INTO check_card(id_check_card,id_account,name_check_card) VALUES (card_num,(SELECT account.id_account from account WHERE account.id_customer=pro_customer_id),pro_card_name);

END//
create procedure create_credit_card(
	pro_customer_id VARCHAR(45),
    pro_bank_name VARCHAR(45),
    pro_card_name VARCHAR(45)
)
BEGIN 

	DECLARE card_num int;
    DECLARE temp_bank int;
    DECLARE temp_date_payment INT;
    DECLARE temp_min_payment INT;
    
set temp_bank=(SELECT bank.id_bank from bank WHERE bank.name_bank=pro_bank_name);
if (temp_bank=1)THEN set temp_date_payment=25,temp_min_payment=300000;
	ELSEIF (temp_bank=2) THEN set temp_Date_payment=27,temp_min_payment=350000;
	ELSEIF (temp_bank=3) THEN set temp_Date_payment=28,temp_min_payment=400000;
END IF;

	SELECT count(*)+1000
	INTO card_num
	FROM credit_card;

	UPDATE account SET  account.card_apply_status=1 WHERE account.id_customer=pro_customer_id
    and account.id_bank=(temp_bank);
    INSERT INTO credit_card(id_credit_card,id_account,name_credit_card,date_payment,min_payment) VALUES (card_num,(SELECT account.id_account from account WHERE account.id_customer=pro_customer_id),pro_card_name,temp_date_payment,temp_min_payment);
END//

-- 아이디,전화번호,사용자이름
call create_customer('000217','010-2930-6833','양준혁')// 
call create_customer('000317','010-3782-1103','온순이')// 
call create_customer('000517','010-1234-5364','상명이')// 

-- 초기자본설정 - 아이디,금액
call set_cash_amount('000217',200000)//
call set_cash_amount('000517',100000)//

-- ex)#1-9	000217의 일별 수입, 지출 기록
SELECT id_customer as '아이디',DATE_FORMAT(date_transaction,'%Y-%m-%d') as '거래날짜', income_transaction as '수입금액',spending_transaction as '지출금액'  from transaction WHERE (income_transaction>0 or spending_transaction>0) and YEAR(date_transaction)=2022 and id_customer='000217' ORDER BY date_transaction ASC//

-- ex)#1-10 000217의 주별 수입, 지출 통계
SELECT id_customer as '아이디',DATE_FORMAT(DATE_SUB(`date_transaction`, INTERVAL (DAYOFWEEK(`date_transaction`)-1) DAY), '%Y-%m-%d') as '거래날짜시작', DATE_FORMAT(DATE_SUB(`date_transaction`, INTERVAL (DAYOFWEEK(`date_transaction`)-7) DAY), '%Y-%m-%d') as '거래날짜끝',DATE_FORMAT(`date_transaction`, '%Y%U') AS `date`,sum(income_transaction) as '수입금액',sum(spending_transaction) as '지출금액'  from transaction WHERE (income_transaction>0 or spending_transaction>0) and YEAR(date_transaction)=2022 and id_customer='000217' group by date ORDER BY date_transaction ASC//

-- ex)#1-11	000217의 월별 수입, 지출 통계
SELECT id_customer as '아이디',DATE_FORMAT(date_transaction,'%Y-%m') as '거래날짜', sum(income_transaction) as '수입금액',sum(spending_transaction) as '지출금액'  from transaction WHERE (income_transaction>0 or spending_transaction>0) and YEAR(date_transaction)=2022 and id_customer='000217' GROUP BY substring(date_transaction,1,7) ORDER BY date_transaction DESC//

-- ex)#1-12	000217의 지출항목별 월별 기록
SELECT id_customer as '아이디',type_transaction as '지출항목',DATE_FORMAT(date_transaction,'%Y-%m') as '거래날짜', sum(income_transaction) as '수입금액',sum(spending_transaction) as '지출금액'  from transaction WHERE (income_transaction>0 or spending_transaction>0) and YEAR(date_transaction)=2022 and id_customer='000217' GROUP BY type_transaction,substring(date_transaction,1,7) ORDER BY date_transaction ASC//

-- ex)#1-13	 000217의 자산별 통계 (현금, 계좌잔고)
SELECT cash.id_customer as '사용자아이디',cash.amount_cash as '현금총액',account.balance as '계좌잔고' from cash,account WHERE cash.id_customer = '000217'and account.id_customer = '000217'//


-- #2-1 계좌개설 - 개설할은행,개설날짜
call create_account('000217','국민은행',20221100)//
call create_account('000317','국민은행',20221122)//
call create_account('000517','신한은행',20220930)//

-- #2-1 입금 - 아이디,거래발생원인,거래유형,금액,날짜,항목,소항목
call income('000217',NULL,'입금',100000,20221112090000,'입금',NULL)//
call income('000217',NULL,'입금',40000,20221112090000,'입금','잔고추가')//
call income('000217','직거래','현금',10000,20221112090000,'중고나라',NULL)//

-- #2-2 카드생성 - 아이디,카드은행사,별명
call create_check_card('000217','국민은행','국민체크카드')//
call create_credit_card('000217','국민은행','국민신용카드')//
call create_check_card('000517','신한은행','신한체크카드')//
call create_credit_card('000517','신한은행','신한신용카드')//
-- #2-3 지출 - 아이디,거래발생원인,거래유형,금액,날짜,항목,소항목
call spend('000217','상명도서관','체크카드',5000,20221202090000,'책','학교교재')//
call spend('000217','카페 ING','체크카드',2000,20221208090000,'식사','음료')//
-- #2-4
call spend('000217','학생식당','신용카드',6500,20221208120000,'식사','식사')//
call spend('000217','상명슈퍼','현금',2000,20221208180000,'식자재','당근')//

-- 추가 지출
call spend('000217','순양전자','체크카드',150000,20221208193000,'가전제품','냉장고')//
call spend('000217','순양전자','신용카드',120000,20221208150000,'가전제품','에어컨')//

-- 계좌이체 - 아이디,상대계좌번호,금액,날짜,항목,소항목. 상대방의 아이디에도 거래내역이 찍힌 것 확인 가능
call transfer ('000217',2002,10000,202212190000,'2002에 계좌이체','빚 갚기')//
call transfer ('000217',2002,2500,20221211190000,'2002에 계좌이체','카카오페이')//

-- 계좌번호가 1000인 계좌의 이율 업데이트, 항목 및 목표 설정
call update_fixed_income(1000)//
call update_fixed_spending(1000)//
call spend_type_target('000217','식사','음료','1달에30만원이하로사용하기')//
call spend_type_target('000217','식사','식사','1달에30만원이하로사용하기')//
call spend_type_target('000217','경조사','축의금',NULL)//

-- #2-5	000217사용자의 12월 18일 지출항복별 지출금액
SELECT id_customer as '아이디', type_transaction as '지출항목',date_transaction as '거래날짜', sum(spending_transaction) as '지출금액' from transaction 
WHERE transaction.id_customer='000217' and spending_transaction>0 and DATE(date_transaction)='2022-12-08' 
GROUP BY type_transaction 
ORDER BY type_transaction DESC,smalltype_transaction ASC//

-- #2-6	000217사용자의 11월의 수입합계,지출합계
SELECT id_customer as '아이디',DATE_FORMAT(date_transaction,'%Y-%m') as '거래날짜', sum(income_transaction) as '수입금액',sum(spending_transaction) as '지출금액' from transaction 
WHERE (income_transaction>0 or spending_transaction>0) and MONTH(transaction.date_transaction)=11 and YEAR(date_transaction)=2022 
GROUP BY transaction.id_customer having transaction.id_customer='000217' 
ORDER BY date_transaction ASC//

-- #2-7	000217사용자의 12월 1주째 수입항목별 합계와 지출항목별 합계. 12월2일 5000원 지출있음
SELECT id_customer as '아이디',DATE_FORMAT(date_transaction,'%Y-%m') as '거래날짜', sum(income_transaction) as '수입금액',sum(spending_transaction) as '지출금액'  from transaction 
WHERE (income_transaction>0 or spending_transaction>0) and MONTH(date_transaction)=12 and YEAR(date_transaction)=2022 and DAY(date_transaction) between 1 and 3 
GROUP BY transaction.id_customer having transaction.id_customer='000217' 
ORDER BY date_transaction ASC//

-- #2-8	000217사용자의 신용카드11월 기준 월 결제굼액 총액, 최소결제금액
SELECT expect.id_credit_card as '신용카드번호',DATE_FORMAT(date_approve_expect,'%Y-%m') as '승인날짜',DATE_FORMAT(date_expect_payment,'%Y-%m') as '결제예정일', sum(amount_expect) as '결제예정금액', credit_card.min_payment as '최소결제금액' from expect,credit_card,account 
WHERE expect.id_credit_card=credit_card.id_credit_card and account.id_customer='000217'//

-- #2-9	000217사용자의 11월 기준 월 수입, 지출, 예상지출액 총액
SELECT id_customer as '아이디',DATE_FORMAT(date_transaction,'%Y-%m') as '거래날짜', sum(income_transaction) as '수입금액',sum(spending_transaction) as '지출금액' , (SELECT sum(amount_expect) from expect,credit_card,account 
WHERE expect.id_credit_card=credit_card.id_credit_card and  MONTH(expect.date_approve_expect)=11 and YEAR(expect.date_approve_expect)=2022 and account.id_customer='000217' ) as '내월 예정 지출액' from transaction WHERE (income_transaction>0 or spending_transaction>0) and item_transaction not like"%신용카드%"  and MONTH(transaction.date_transaction)=11 and YEAR(date_transaction)=2022 
GROUP by id_customer HAVING id_customer='000217'//

-- #2-10	000217사용자의 2022년 기준 주 지출항목별 지출비율 확인
SELECT id_customer as '아이디',type_transaction as '지출항목',DATE_FORMAT(date_transaction,'%Y') as '거래날짜',sum(spending_transaction) as '지출금액' , ROUND(sum(spending_transaction)/(SELECT sum(spending_transaction) from transaction 
WHERE spending_transaction>0 and YEAR(date_transaction)=2022 )*100,1) as '지출비율(%)' from transaction WHERE spending_transaction>0 and YEAR(date_transaction)=2022 
GROUP BY type_transaction having transaction.id_customer='000217' 
ORDER BY date_transaction ASC//

-- #2-11	000217사용자의 2022년 기준 식사 지출항목에 대한 서브항목의 비율 확인
SELECT id_customer as '아이디',type_transaction as '지출항목',smalltype_transaction as '서브항목',DATE_FORMAT(date_transaction,'%Y') as '거래날짜',spending_transaction as '지출금액' , ROUND(spending_transaction/(SELECT sum(spending_transaction) from transaction 
WHERE spending_transaction>0 and type_transaction like "식사" and YEAR(date_transaction)=2022 )*100,1) as '지출비율(%)' from transaction 
WHERE spending_transaction>0 and YEAR(date_transaction)=2022 and type_transaction like "%식사%" having transaction.id_customer='000217' 
ORDER BY date_transaction DESC//

-- 날짜가 비어있을 경우 현재시간 적용(NOW 사용)
call income('000217','직거래','현금',10000,NULL,'당근마켓','안쓰는이어폰판매')//

-- 000517의 수입, 지출, 계좌이체 확인해보기
call income('000517',NULL,'입금',30000,20221112090000,'입금',NULL)//
call spend('000517','국민은행','출금',500,20221208090000,'출금',NULL)//
call spend('000517','상명슈퍼','현금',2000,20221208090000,'슈퍼마켓',NULL)//
call transfer ('000517',1000,2500,20221209190000,'1000에 계좌이체','카카오페이돌려줌')//
-- 000517의 거래내역
SELECT id_customer as '아이디', date_transaction as '거래날짜',place_Transaction as 거래발생원인, income_transaction as '수입금액',spending_transaction as '지출금액', balance_cash as '현금잔액',balance_account as '계좌잔고', type_transaction as '항목',smalltype_transaction as '소항목'
from transaction
WHERE id_customer='000517'
ORDER BY date_transaction ASC//

-- 000217의 거래내역 확인해보기
SELECT id_customer as '아이디', date_transaction as '거래날짜',place_Transaction as 거래발생원인, income_transaction as '수입금액',spending_transaction as '지출금액', balance_cash as '현금잔액',balance_account as '계좌잔고', type_transaction as '항목',smalltype_transaction as '소항목'
from transaction
WHERE id_customer='000217'
ORDER BY date_transaction asc//

-- 전체 거래내역
SELECT id_customer as '아이디', date_transaction as '거래날짜',place_Transaction as 거래발생원인, income_transaction as '수입금액',spending_transaction as '지출금액', balance_cash as '현금잔액',balance_account as '계좌잔고', type_transaction as '항목',smalltype_transaction as '소항목'
from transaction
ORDER BY date_transaction//