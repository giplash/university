import mysql from 'mysql2';

const pool = mysql.createPool({
    host: 'localhost',
    user: 'root',
    database: 'task-3',
    password: 'rootroot'
})

export default pool.promise();