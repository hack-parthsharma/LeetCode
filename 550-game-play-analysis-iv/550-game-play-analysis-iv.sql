select round(
    ifnull(
        (   
            select count(distinct a.player_id)
            from Activity as a join Activity as b
            on a.player_id = b.player_id and datediff(b.event_date, a.event_date) = 1
            where a.event_date = (
                select min(event_date) from Activity where player_id = a.player_id
            )
        ) 
        / -- devided by
        (   select count(distinct player_id) from Activity   ),
    0),
2)
as fraction;
