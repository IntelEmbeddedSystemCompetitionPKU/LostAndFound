#signup
curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signup

#signin
curl -i -H "Content-Type:application/json" -X POST -d {\"name\":\"Alice\",\"passwd\":\"123abc\"} http://localhost:5000/signin
# get lost list
curl -i -H "Content-Type:application/json" http://localhost:5000/lost_list/20180520_20180521_校园卡_红色

