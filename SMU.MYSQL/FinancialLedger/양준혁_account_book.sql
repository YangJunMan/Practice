create database 양준혁_account_book;
use 양준혁_account_book;

/* 
ERD 생성

사용자. 은행. 계좌. 카드. 내역 저장
*/

CREATE TABLE `Customer` (
	`id_customer`	VARCHAR(45)	NOT NULL,
	`phone_customer`	VARCHAR(45)	NULL,
	`name_customer`	VARCHAR(45)	NULL
);

CREATE TABLE `Account` (
	`id_account`	VARCHAR(45)	NOT NULL,
	`id_bank`	INT	NOT NULL,
	`id_customer`	VARCHAR(45)	NOT NULL,
	`name_bank`	VARCHAR(45)	NULL,
	`name_customer`	VARCHAR(45)	NULL,
	`date_account`	DATE	NULL,
	`card_apply_status`	bool	NULL,
	`checkcard_apply_status`	bool	NULL,
	`balance`	INT	NULL
);

CREATE TABLE `Bank` (
	`id_bank`	INT	NOT NULL,
	`name_bank`	VARCHAR(45)	NULL
);

CREATE TABLE `transaction` (
	`id_transaction`	INT	NOT NULL,
	`id_customer`	VARCHAR(45)	NOT NULL,
	`date_transaction`	DATETIME	NULL,
	`place_transaction`	VARCHAR(45)	NULL,
	`item_transaction`	VARCHAR(45)	NULL,
	`income_transaction`	INT	NULL,
	`spending_transaction`	INT	NULL,
	`balance_cash`	INT	NULL,
	`balance_account`	INT	NULL,
	`type_transaction`	VARCHAR(45)	NULL,
	`smalltype_transaction`	VARCHAR(45)	NULL
);

CREATE TABLE `check_card` (
	`id_check_card`	INT	NOT NULL,
	`id_account`	VARCHAR(45)	NOT NULL,
	`name_check_card`	VARCHAR(45)	NULL
);

CREATE TABLE `fixed_spending` (
	`id_account`	VARCHAR(45)	NOT NULL,
	`percent_fixed_spending`	INT	NULL,
	`amount_fixed_spending`	INT	NULL
);

CREATE TABLE `Cash` (
	`id_customer`	VARCHAR(45)	NOT NULL,
	`amount_cash`	INT	NULL
);

CREATE TABLE `credit_card` (
	`id_credit_card`	INT	NOT NULL,
	`id_account`	VARCHAR(45)	NOT NULL,
	`name_credit_card`	VARCHAR(45)	NULL,
	`date_payment`	INT	NULL,
	`min_payment`	INT	NULL
);

CREATE TABLE `expect` (
	`id_expect`	INT	NOT NULL,
	`id_credit_card`	INT	NOT NULL,
	`date_expect_payment`	DATE	NULL,
	`amount_expect`	INT	NULL,
	`date_approve_expect`	DATE	NULL
);

CREATE TABLE `fixed_income` (
	`id_account`	VARCHAR(45)	NOT NULL,
	`percent_fixed_income`	INT	NULL,
	`amount_fixed_income`	INT	NULL
);

CREATE TABLE `target_spending` (
	`id_target_spending`	int	NOT NULL,
	`id_customer`	VARCHAR(45)	NOT NULL,
	`type_spending`	VARCHAR(45)	NULL,
	`smalltype_spending`	VARCHAR(45)	NULL,
	`target_type_spending`	VARCHAR(45)	NULL
);

ALTER TABLE `Customer` ADD CONSTRAINT `PK_CUSTOMER` PRIMARY KEY (
	`id_customer`
);

ALTER TABLE `Account` ADD CONSTRAINT `PK_ACCOUNT` PRIMARY KEY (
	`id_account`,
	`id_bank`,
	`id_customer`
);

ALTER TABLE `Bank` ADD CONSTRAINT `PK_BANK` PRIMARY KEY (
	`id_bank`
);

ALTER TABLE `transaction` ADD CONSTRAINT `PK_TRANSACTION` PRIMARY KEY (
	`id_transaction`,
	`id_customer`
);

ALTER TABLE `check_card` ADD CONSTRAINT `PK_CHECK_CARD` PRIMARY KEY (
	`id_check_card`,
	`id_account`
);

ALTER TABLE `fixed_spending` ADD CONSTRAINT `PK_FIXED_SPENDING` PRIMARY KEY (
	`id_account`
);

ALTER TABLE `Cash` ADD CONSTRAINT `PK_CASH` PRIMARY KEY (
	`id_customer`
);

ALTER TABLE `credit_card` ADD CONSTRAINT `PK_CREDIT_CARD` PRIMARY KEY (
	`id_credit_card`,
	`id_account`
);

ALTER TABLE `expect` ADD CONSTRAINT `PK_EXPECT` PRIMARY KEY (
	`id_expect`,
	`id_credit_card`
);

ALTER TABLE `fixed_income` ADD CONSTRAINT `PK_FIXED_INCOME` PRIMARY KEY (
	`id_account`
);

ALTER TABLE `target_spending` ADD CONSTRAINT `PK_TARGET_SPENDING` PRIMARY KEY (
	`id_target_spending`,
	`id_customer`
);

ALTER TABLE `Account` ADD CONSTRAINT `FK_Bank_TO_Account_1` FOREIGN KEY (
	`id_bank`
)
REFERENCES `Bank` (
	`id_bank`
);

ALTER TABLE `Account` ADD CONSTRAINT `FK_Customer_TO_Account_1` FOREIGN KEY (
	`id_customer`
)
REFERENCES `Customer` (
	`id_customer`
);

ALTER TABLE `transaction` ADD CONSTRAINT `FK_Customer_TO_transaction_1` FOREIGN KEY (
	`id_customer`
)
REFERENCES `Customer` (
	`id_customer`
);

ALTER TABLE `check_card` ADD CONSTRAINT `FK_Account_TO_check_card_1` FOREIGN KEY (
	`id_account`
)
REFERENCES `Account` (
	`id_account`
);

ALTER TABLE `fixed_spending` ADD CONSTRAINT `FK_Account_TO_fixed_spending_1` FOREIGN KEY (
	`id_account`
)
REFERENCES `Account` (
	`id_account`
);

ALTER TABLE `Cash` ADD CONSTRAINT `FK_Customer_TO_Cash_1` FOREIGN KEY (
	`id_customer`
)
REFERENCES `Customer` (
	`id_customer`
);

ALTER TABLE `credit_card` ADD CONSTRAINT `FK_Account_TO_credit_card_1` FOREIGN KEY (
	`id_account`
)
REFERENCES `Account` (
	`id_account`
);

ALTER TABLE `expect` ADD CONSTRAINT `FK_credit_card_TO_expect_1` FOREIGN KEY (
	`id_credit_card`
)
REFERENCES `credit_card` (
	`id_credit_card`
);

ALTER TABLE `fixed_income` ADD CONSTRAINT `FK_Account_TO_fixed_income_1` FOREIGN KEY (
	`id_account`
)
REFERENCES `Account` (
	`id_account`
);

ALTER TABLE `target_spending` ADD CONSTRAINT `FK_Customer_TO_target_spending_1` FOREIGN KEY (
	`id_customer`
)
REFERENCES `Customer` (
	`id_customer`
);


-- 기본 은행정보
Insert into bank(id_bank,name_bank) values (1,'국민은행');
Insert into bank(id_bank,name_bank) values (2,'신한은행');
Insert into bank(id_bank,name_bank) values (3,'농협은행');