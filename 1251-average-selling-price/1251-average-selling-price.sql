# Write your MySQL query statement below
select Prices.product_id, round(sum(units*price)/sum(UnitsSold.units), 2) average_price from UnitsSold, Prices
where UnitsSold.product_id = Prices.product_id and UnitsSold.purchase_date between Prices.start_date and Prices.end_date group by UnitsSold.product_id;

