import express from 'express';
import path from 'path';
import db from './utils/db';

const app = express();

db.execute('SELECT * FROM test')

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'vsiews'));

app.use(express.static(path.join(__dirname, 'public')));

app.get('*', (req, res) => {
  res.render('index');
});

app.listen(3000, () => {
  console.log('App listening on http://127.0.0.1:3000');
});
