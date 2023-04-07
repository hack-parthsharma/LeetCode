# Write your MySQL query statement below
select t.student_id, t.student_name, t.subject_name, 
    if(e.attended_exams is null, 0, e.attended_exams) as attended_exams
from
    (select *
    from Students
    cross join Subjects) t
left join 
    (select *, count(*) as attended_exams
    from Examinations
    group by student_id, subject_name) e
on t.student_id = e.student_id and t.subject_name = e.subject_name
order by student_id, subject_name