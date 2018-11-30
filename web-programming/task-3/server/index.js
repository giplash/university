import express from 'express';
import path from 'path';
import setRouting from './routes';

const app = express();

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use(express.static(path.join(__dirname, 'public')));

setRouting(app);

app.listen(3000, () => {
  console.log('App listening on http://127.0.0.1:3000');
});
