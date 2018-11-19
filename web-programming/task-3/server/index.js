import express from 'express';
import path from 'path';

const app = express();

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.static(path.join(__dirname, 'public')));

app.get('*', (req, res) => {
  res.render('index');
});

app.listen(3000, () => {
  console.log('App listening on http://127.0.0.1:3000');
});
